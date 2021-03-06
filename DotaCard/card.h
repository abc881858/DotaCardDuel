#ifndef CARD_H
#define CARD_H

#include <QCursor>
#include <QGraphicsPixmapItem>
#include <QList>

#define No_Area 0
#define Deck_Area 1
#define Hand_Area 2
#define Fieldyard_Area 3
#define Fieldground_Area 4
#define Graveyard_Area 5
#define EnemyDeck_Area 6
#define EnemyHand_Area 7
#define EnemyFieldyard_Area 8
#define EnemyFieldground_Area 9
#define EnemyGraveyard_Area 10

#define No_Type 0

class Card : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Card();

    enum FingerFlag
    {
        NoFlag,
        Effect, //可以发动怪兽效果
        SpecialSummon,
        NormalSummon,
        SetCard,
        FlipSummon, //可以翻转召唤
        DefencePosition, //可以防守表示
        AttackPosition, //可以攻击表示
        Attack
    };

    //    enum
    //    {
    //        NoArea = 0,
    //        DeckArea = 1,
    //        HandArea = 2,
    //        FieldyardArea = 3,
    //        FieldgroundArea = 4,
    //        GraveyardArea = 5,
    //        EnemyDeckArea = 6,
    //        EnemyHandArea = 7,
    //        EnemyFieldyardArea = 8,
    //        EnemyFieldgroundArea = 9,
    //        EnemyGraveyardArea = 10
    //    };

    //    怪兽 Monster
    //    通常怪兽 Normal monster
    //    效果怪兽 Effect monster
    //    仪式怪兽 Ritual monster
    //    融合怪兽 Fusion monster
    //    同调怪兽 Synchro monster
    //    二重怪兽 Gemini monster
    //    灵魂怪兽 Spirit monster
    //    卡通怪兽 Toon monster
    //    调整/协调（怪兽） Turner
    //    同盟怪兽 Union monster
    //    超量怪兽 XYZ monster

    //    魔法 Spell
    //    通常魔法 Normal spell
    //    永续魔法 Continuous spell
    //    装备魔法 Equip spell
    //    速攻魔法 Quickly-play spell
    //    场地魔法 Field spell
    //    仪式魔法Ritual spell

    //    陷阱 Trap
    //    通常陷阱 Normal trap
    //    永续陷阱 Continuous trap
    //    反击陷阱 Counter trap
    enum
    {
        NoType,
        NormalMonster,
        EffectMonster,
        NormalSpell,
        ContinuousSpell,
        EquipSpell,
        QuicklyplaySpell,
        FieldSpell,
        NormalTrap,
        ContinuousTrap,
        CounterTrap
    };

    //Earth（地属性）、Water（水属性）、Fire（炎属性）、Wind（风属性）、Light（光属性）、Dark（闇属性）
    enum
    {
        Earth,
        Water,
        Fire,
        Wind,
        Light,
        Dark
    };

    //Type：Dragon（龙族）、Spellcaster（魔法使族）、Zombie（不死族）、Warrior（战士族）、
    //Beast-Warrior（兽战士族）、Beast（兽族）、Winged Beast（鸟兽族）、Fiend（恶魔族）、
    //Fairy（天使族）、Insect（昆虫族）、Dinosaur（恐龙族）、Reptile（爬虫族）、Fish（鱼族）、
    //Sea Serpent（海龙族）、Machine（机械族）、Thunder（雷族）、Aqua（水族）、Pyro（炎族）、
    //Rock（岩石族）、Plant（植物族）
    enum
    {
        Dragon,
        Spellcaster,
        Zombie,
        Warrior,
        BeastWarrior,
        Beast,
        WingedBeast,
        Fiend,
        Fairy,
        Insect,
        Dinosaur,
        Reptile,
        Fish,
        SeaSerpent,
        Machine,
        Thunder,
        Aqua,
        Pyro,
        Rock,
        Plant
    };

    //    CardFlags getCardFlags() const;
    //    void setCardFlag(CardFlag flag, bool enabled = true);
    //    void setCurrentflag(Card::CardFlag flag);

    int getISDN() const;

    QString getName() const;
    void setName(const QString& value);

    int getArea() const;
    void setArea(int value);

    QString getDescription() const;

    bool getFace() const;
    void setFace(bool value);

    bool getStand() const;
    void setStand(bool value);

    bool getInActive() const;
    void setInActive(bool value);

    //    Card::CardFlags testAll();
    bool testSpecialSummon();
    bool testNormalSummon();
    bool testSetCard();
    bool testFlipSummon();
    bool testDefencePosition();
    bool testAttackPosition();
    bool testAttack();

    virtual bool testEffect() { return false; }
    virtual void effect(){}

    bool getChangePosition() const;
    void setChangePosition(bool value); //area需要

    int getIndex() const; //area 需要这个函数
    void setIndex(int value);

    bool getOneTurnOneEffect() const;
    void setOneTurnOneEffect(bool value);
    bool getOneTurnHandEffect() const;
    void setOneTurnHandEffect(bool value);
    bool getOneTurnOneAttack() const;
    void setOneTurnOneAttack(bool value);

    bool isMonstor() { return (type == NormalMonster || type == EffectMonster); }

    int getType() const;
    void setType(int value);

    bool getBuff_604() const;
    void setBuff_604(bool value);

    bool getBuff_602() const;
    void setBuff_602(bool value);

    int getATK() const;
    void setATK(int value);

    int getDEF() const;
    void setDEF(int value);

    int getCurrentATK() const;
    void setCurrentATK(int value);

    int getCurrentDEF() const;
    void setCurrentDEF(int value);

    void showCurrentFingerFlag();

    int getLevel() const;
    void setLevel(int value);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    int ISDN; //图片唯一ID
    QString name; //图片名字
    int type; //类型
    int ATK;
    int DEF;
    int currentATK;
    int currentDEF;
    int level; //等级
    int attribute; //种族
    int index; //从左往右数第几张(第1张是index==0)
    QString description; //卡牌描述
    bool buff_604; //猛犸分裂buff
    bool buff_602; //光法致盲buff

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    FingerFlag currentFingerFlag;
    QList<FingerFlag> allFingerFlags;
    QCursor cursorNoFlag;
    QCursor cursorEffect;
    QCursor cursorSpecialSummon;
    QCursor cursorNormalSummon;
    QCursor cursorSetCard;
    QCursor cursorFlipSummon;
    QCursor cursorDefencePosition;
    QCursor cursorAttackPosition;
    QCursor cursorAttack;
    QPixmap lighterPixmap;
    QPixmap originalPixmap;

    bool isRotate; //是否显示为横置
    bool isBack; //是否显示为背面
    bool isField; //是否显示为field文件夹的卡（即50*72类型）
    int area; //卡牌位置，比如在手上或者在前场
    bool face; // 卡牌表侧表示或者里侧表示
    bool stand; // 卡牌攻击表示或者防御表示
    //    CardFlags myflags; //右键可以显示的全部cursor
    //    Card::CardFlag currentflag; //当前如果鼠标移上去该显示的cursor

    bool changePosition; //每回合可以变更一次攻防表示
    bool oneTurnOneEffect; //每回合从场地上可以发动一次
    bool oneTurnHandEffect; //每回合从手上可以发动一次
    bool oneTurnOneAttack; //每回合可以从场地上攻击一次
    //以后已经还有每回合可以从墓地、除外、额外发动一次
    //    int currentRequire; //当前选择卡牌的原因，不能放在发动卡里，也不能放在选择卡里，请使用全局Rule里的pickRequirement

    int debuff; // 光之守卫 需要用到

signals:
    void hoverEnter();
    void hoverLeave();
    void normalSummon();
    void setCard();
    void tribute();
    void pickTarget();
    void pressSword();
    void activeEffect();
    void activeHandEffect();
};

//Q_DECLARE_OPERATORS_FOR_FLAGS(Card::CardFlags)

///////////////////////////////////////////////

/*!
 * \brief 半人马酋长
 *
 * ①将这张卡作为祭品发动，强制结束对方的战斗阶段。
 * 若这张卡装备了“dota-跳刀”，
 * 则可以改为丢弃一张手牌发动
 *
 * ②你的每回合一次，
 * 你可以让自己场上名字带有“dota”的怪兽全部变为攻击表示或防守表示，
 * 若这张卡装备了“dota-阿哈利姆神杖”时，
 * 同时令自己场上名字带有“dota”的怪兽的攻击力（或防御力）上升自己原本攻击力（或防御力）的一半。
 *
 */
class CentaurWarrunner : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE CentaurWarrunner();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 光之守卫
 *
 * ①一回合一次，当有“dota-光之守卫”以外名字带有“dota”的加入手牌时可以发动，
 * 将那只怪兽特殊召唤至场上，若这张卡装备了“dota-阿哈利姆神杖”。
 * 则改此效果为：一回合一次，可以从手牌·卡组特殊召唤一只“dota-光之守卫”以外的名字带有“dota”的怪兽。
 *
 * ②这张卡在手牌存在时，一回合一次，将自己场上一只“dota-光之守卫”以外的名字带有“dota”的怪兽返回手牌。
 *
 * ③一回合一次，选择对方场上的一只怪兽发动，选择的怪兽在进行攻击宣言前必须丢弃一张手牌。
 *
 */
class KeeperoftheLight : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE KeeperoftheLight();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 恶魔巫师
 *
 * 一回合一次，选择下面的其一的效果发动：
 * 1、选择对方场上一张怪兽发动，选择的怪兽变为里侧守备表示。
 * 2、选择对方场上一张里侧守备表示的怪兽发动，选择的怪兽破坏。
 * 当这张卡装备了“dota-阿哈利姆神杖”时，同时破坏选择怪兽两边的卡。
 *
 */
class Lion : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Lion();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 半人猛犸
 *
 * ①一回合一次，令自己场上一只名字带有“dota”的怪兽，
 * 在你下回合开始前攻击力上升400点，且在攻击之后，
 * 可以降低600点攻击对对方场上所有怪兽进行一次攻击。
 *
 * ②将这张卡装备的“dota-跳刀”送去墓地，
 * 将对方场上的怪兽全部转为正面攻击表示，攻击力变为0，
 * 且在对方回合结束前不能进行攻击不能更变形式。
 *
 */
class Magnus : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Magnus();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 地穴刺客
 *
 * ①一回合一次，丢弃一张手牌，指定对方场上一只表侧表示的怪兽发动，
 * 对方受到怪兽等级的一半（向下取整且最少为1）*400点伤害，并丢弃一张手牌。
 *
 * ②这张卡有一次不会被破坏，并破坏的种类发动以下效果。
 * 战斗破坏：给与攻击怪兽控制者等同于攻击怪兽攻击的伤害。
 * 效果破坏：破坏那张卡，若那张卡需要指定的怪兽在场上才能发动，则指定的怪兽一起破坏。
 *
 * ③一回合一次，丢弃一张手卡发动，这张卡在下次攻击的伤害计算阶段结束前攻击力上升600，且不会成为攻击和卡的效果对象。
 *
 */
class NyxAssassin : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE NyxAssassin();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 大魔导师
 *
 * 这张卡在自己场上表侧表示存在时，自己场上名字带有“dota”的怪兽一回合一次不会被卡的效果破坏。
 * 一回合一次，选择一个效果发动：
 * 1、对方怪兽你的下回合开始前攻击力下降500；
 * 2、你获得对方的一个怪兽效果直到回合结束。当你装备“dota-阿哈利姆神杖”时，
 * 你的1、2效果可以同时发动且你的2效果1回合可以使用2次（覆盖上次获得的效果且该回合不能再次获得同一效果）
 *
 */
class Rubick : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Rubick();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 巨牙海民
 *
 * 这张卡在进行攻击时，可以从手牌表侧攻击特殊召唤一只名字带有“dota”的怪兽，
 * 伤害计算阶段，这张卡的攻击力上升特殊召唤的怪兽攻击力的一半，
 * 这回合，由这个效果特殊召唤而来的怪兽不需要装备“dota-跳刀”便可以发动装备“dota-跳刀”的效果。
 * 一回合一次，这张卡攻击时，若目标怪兽的防御力低于你的攻击力，此次战斗对对方造成的战斗伤害翻倍。
 *
 */
class Tusk : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Tusk();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 不朽尸王
 *
 * 一回合一次，3回合内使对方场上的一只怪兽守备力下降300点，这张卡的守备力上升300点。
 * 一回合一次，你可以弃一张手牌，在自己场上特殊召唤与对方场上怪兽数量相同的“僵尸衍生物”
 * （1星，不死族暗属性，攻500·守0，不能作为祭品、同调及超量素材，
 * 攻击对方守备力低于800的怪兽时，伤害计算阶段攻击力上升500，受到的战斗伤害为0。
 * 每进行一次攻击，伤害计算后被攻击怪兽攻·守下降200至你下回合结束。）
 *
 */
class Undying : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Undying();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 复仇之魂
 *
 * ①当自己场上有“dota-复仇之魂”外的名字带有“dota”怪兽时发动。
 * 你选择一名对方4星以下的怪兽，这张卡和该怪兽的控制权交换直到回合结束，
 * 交换控制权的怪兽不能作为祭品，也不能进行攻击。
 * 若这张卡装备了“dota-阿哈利姆神杖”则可以指定对方任何怪兽且不需要自己场上存在名字带有“dota”的怪兽，
 * 当这张卡的控制权转移给对方时，你可以令这张卡装备的“dota-阿哈利姆神杖”回到手牌。
 *
 * ②只要这张卡在场上，名字带有“dota”的怪兽攻击力上升300。
 *
 * ③一回合一次，你可以指定一名怪兽使其防御力降低800。
 *
 */
class VengefulSpirit : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE VengefulSpirit();
    virtual bool testEffect();
    virtual void effect();
};

/*!
 * \brief 奥林匹斯之王
 *
 * ①当自己场上存在“dota-奥林匹斯之王”以外名字带有“dota”的怪兽时，这张卡可以从手牌特殊召唤。
 *
 * ②一回合一次，丢弃一张手牌发动，破坏对方场上一只怪兽。
 *
 * ③一回合一次，丢弃2张手牌发动，对方场上怪兽守备力降低1000点，因此效果使怪兽守备力降低至0的场合，破坏此怪兽。
 * 若这张卡装备了“dota-阿哈利姆神杖”时，改为降低2000点守备力。
 *
 */
class Zeus : public Card
{
    Q_OBJECT
public:
    Q_INVOKABLE Zeus();
    virtual bool testEffect();
    virtual void effect();
};

#endif // CARD_H
