#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

//    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    
    auto func1 = CC_CALLBACK_1(HelloWorld::menuCloseCallback, this);
    //auto func2 = [](Ref* p){ CCLOG("閉じるボタンが押された"); };
    //auto func3 = std::bind(&HelloWorld::menuCloseCallback, this, std::placeholders::_1);
    //auto func4 = [this](Ref* p){ this->menuCloseCallback(p); };
    auto closeItem = MenuItemImage::create(
                                       "CloseNormal.png",
                                       "CloseSelected.png",
                                       func1);
    closeItem->setPosition(940, 20);

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);

    // テキストの作成
//    auto label = Label::createWithSystemFont("こんにちは世界", "Arial", 50);
//    label->setPosition(480,600);
//    this->addChild(label, 1);
    
//    label->setPosition(900,200);
//    label->setName("label");

//    // 画像の作成
//    auto sprite = Sprite::create("HelloWorld.png");
//    sprite->setPosition(480, 320);
//    this->addChild(sprite, 0);
    
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("UnityChan.plist");
    // ユニティちゃん作成
    char imagePath[256] = {0};
    snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "footwork", 0);
    auto unityChan = Sprite::createWithSpriteFrameName(imagePath);
    unityChan->setScale(2);
    unityChan->setPosition(480, 200);
    unityChan->setName("UnityChan");
    this->addChild(unityChan, 1);
    
    
    Size btnSize = Size(100, 30);
    const float marginX = 5;
    const float marginY = 20;
    const float btnX1 = btnSize.width/2+marginX;
    const float btnX2 = btnX1+btnSize.width+marginX;
    const float btnX3 = btnX2+btnSize.width+marginX;
    const float btnX4 = btnX3+btnSize.width+marginX;
    const float btnX5 = btnX4+btnSize.width+marginX;
    const float btnX6 = btnX5+btnSize.width+marginX;
    const float btnX7 = btnX6+btnSize.width+marginX;
    const float btnX8 = btnX7+btnSize.width+marginX;
    const float btnX9 = btnX8+btnSize.width+marginX;
    const float btnY1 = 640-btnSize.height/2-marginY;
    const float btnY2 = btnY1-btnSize.height-marginY;
    const float btnY3 = btnY2-btnSize.height-marginY*2;
    const float btnY4 = btnY3-btnSize.height-marginY*2;
    const float btnY5 = btnY4-btnSize.height-marginY*2;
    
    auto moveToItem = MenuItemImage::create(
                                            "btn_move_to.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(MoveTo::create(0.5f, Vec2(100,100)));});
    auto moveByItem = MenuItemImage::create(
                                            "btn_move_by.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(MoveBy::create(0.5f, Vec2(65,50)));});
    auto scaleToItem = MenuItemImage::create(
                                             "btn_scale_to.png",
                                             "",
                                             [this](Ref* p){ this->getChildByName("UnityChan")->runAction(ScaleTo::create(0.5f, 0.5f));});
    auto scaleByItem = MenuItemImage::create(
                                             "btn_scale_by.png",
                                             "",
                                             [this](Ref* p){ this->getChildByName("UnityChan")->runAction(ScaleBy::create(1.5f, 1.5f));});
    auto rotateToItem = MenuItemImage::create(
                                              "btn_rotate_to.png",
                                              "",
                                              [this](Ref* p){ this->getChildByName("UnityChan")->runAction(RotateTo::create(0.6f, 180));});
    auto rotateByItem = MenuItemImage::create(
                                              "btn_rotate_by.png",
                                              "",
                                              [this](Ref* p){ this->getChildByName("UnityChan")->runAction(RotateBy::create(0.4f, -45));});
    auto blinkItem = MenuItemImage::create(
                                           "btn_blink.png",
                                           "",
                                           [this](Ref* p){ this->getChildByName("UnityChan")->runAction(Blink::create(2.0f, 6));});
    auto fadeToItem = MenuItemImage::create(
                                            "btn_fade_to.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(FadeTo::create(1.0f, 100));});
    auto fadeInItem = MenuItemImage::create(
                                            "btn_fade_in.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(FadeIn::create(1.0f));});
    auto fadeOutItem = MenuItemImage::create(
                                             "btn_fade_out.png",
                                             "",
                                             [this](Ref* p){ this->getChildByName("UnityChan")->runAction(FadeOut::create(1.0f));});
    auto skewToItem = MenuItemImage::create(
                                            "btn_skew_to.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(SkewTo::create(0.5f, 30, 10));});
    auto skewByItem = MenuItemImage::create(
                                            "btn_skew_by.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(SkewBy::create(0.4f, 10, 20));});
    auto tintToItem = MenuItemImage::create(
                                            "btn_tint_to.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(TintTo::create(0.6f, 180, 0, 0));});
    auto tintByItem = MenuItemImage::create(
                                            "btn_tint_by.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(TintBy::create(0.4f, -10, 20, 20));});
    auto jumpToItem = MenuItemImage::create(
                                            "btn_jump_to.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(JumpTo::create(2, Vec2(100,100), 100, 3));});
    auto jumpByItem = MenuItemImage::create(
                                            "btn_jump_by.png",
                                            "",
                                            [this](Ref* p){ this->getChildByName("UnityChan")->runAction(JumpBy::create(2, Vec2(150,100), 100, 1));});
    
    auto bezierToItem = MenuItemImage::create(
                                            "btn_bezier_to.png",
                                            "",
                                            [this](Ref* p){
                                                ccBezierConfig config;
                                                config.controlPoint_1 = Vec2(900, 200);
                                                config.controlPoint_2 = Vec2(200, 600);
                                                config.endPosition = Vec2(100, 100);
                                                this->getChildByName("UnityChan")->runAction(BezierTo::create(0.6f, config));
                                            });
    auto bezierByItem = MenuItemImage::create(
                                            "btn_bezier_by.png",
                                            "",
                                            [this](Ref* p){
                                                ccBezierConfig config;
                                                config.controlPoint_1 = Vec2(-200, -100);
                                                config.controlPoint_2 = Vec2(200, 300);
                                                config.endPosition = Vec2(100, 100);
                                                this->getChildByName("UnityChan")->runAction(BezierBy::create(0.4f, config));
                                            });
    
    moveToItem->setPosition(btnX1, btnY1);
    moveByItem->setPosition(btnX1, btnY2);
    scaleToItem->setPosition(btnX2, btnY1);
    scaleByItem->setPosition(btnX2, btnY2);
    rotateToItem->setPosition(btnX3, btnY1);
    rotateByItem->setPosition(btnX3, btnY2);
    blinkItem->setPosition(btnX4, btnY1);
    fadeToItem->setPosition(btnX4, btnY2);
    fadeInItem->setPosition(btnX5, btnY1);
    fadeOutItem->setPosition(btnX5, btnY2);
    skewToItem->setPosition(btnX6, btnY1);
    skewByItem->setPosition(btnX6, btnY2);
    tintToItem->setPosition(btnX7, btnY1);
    tintByItem->setPosition(btnX7, btnY2);
    jumpToItem->setPosition(btnX8, btnY1);
    jumpByItem->setPosition(btnX8, btnY2);
    bezierToItem->setPosition(btnX9, btnY1);
    bezierByItem->setPosition(btnX9, btnY2);

    menu->addChild(moveToItem);
    menu->addChild(moveByItem);
    menu->addChild(scaleToItem);
    menu->addChild(scaleByItem);
    menu->addChild(rotateToItem);
    menu->addChild(rotateByItem);
    menu->addChild(blinkItem);
    menu->addChild(fadeToItem);
    menu->addChild(fadeInItem);
    menu->addChild(fadeOutItem);
    menu->addChild(skewToItem);
    menu->addChild(skewByItem);
    menu->addChild(tintToItem);
    menu->addChild(tintByItem);
    menu->addChild(jumpToItem);
    menu->addChild(jumpByItem);
    menu->addChild(bezierToItem);
    menu->addChild(bezierByItem);
    
    // 基本アクションここまで
    
    auto sequenceItem = MenuItemImage::create(
                                            "btn_sequence.png",
                                            "",
                                            [this](Ref* p){
                                                auto action =  Sequence::create(
                                                                                  MoveBy::create(1.0f, Vec2(100,30)),
                                                                                  ScaleBy::create(1.0f, 2.0f),
                                                                                  RotateBy::create(1.0f, 360),
                                                                                  NULL);
                                                this->getChildByName("UnityChan")->runAction(action);
                                            });
    auto spawnItem = MenuItemImage::create(
                                            "btn_spawn.png",
                                            "",
                                           [this](Ref* p){
                                               auto action =  Spawn::create(
                                                                                 MoveBy::create(1.0f, Vec2(100,30)),
                                                                                 ScaleBy::create(1.0f, 2.0f),
                                                                                 RotateBy::create(1.0f, 360),
                                                                                 NULL);
                                               this->getChildByName("UnityChan")->runAction(action);
                                           });
    auto repeatItem = MenuItemImage::create(
                                           "btn_repeat.png",
                                           "",
                                           [this](Ref* p){
                                               auto action = Sequence::create(
                                                                                  MoveBy::create(1.0f, Vec2(50,30)),
                                                                                  ScaleBy::create(1.0f, 1.4f),
                                                                                  RotateBy::create(1.0f, 360),
                                                                                  NULL);
                                               this->getChildByName("UnityChan")->runAction(Repeat::create(action, 4));
                                           });
    auto repeatForeverItem = MenuItemImage::create(
                                           "btn_repeat_forever.png",
                                           "",
                                           [this](Ref* p){
                                               auto action =  Sequence::create(
                                                                               MoveBy::create(1.0f, Vec2(150,0)),
                                                                               JumpBy::create(1.0f, Vec2(0,0), 300, 2),
                                                                               RotateBy::create(1.0f, 720),
                                                                               MoveBy::create(1.0f, Vec2(-150,0)),
                                                                               JumpBy::create(1.0f, Vec2(0,0), 200, 2),
                                                                               NULL);
                                               this->getChildByName("UnityChan")->runAction(RepeatForever::create(action));
                                           });
    auto delayTimeItem = MenuItemImage::create(
                                                   "btn_delay_time.png",
                                                   "",
                                                   [this](Ref* p){
                                                       auto action =  Sequence::create(
                                                                                       MoveBy::create(1.0f, Vec2(200,-30)),
                                                                                       DelayTime::create(1.0f),
                                                                                       RotateBy::create(1.0f, 360),
                                                                                       DelayTime::create(1.0f),
                                                                                       JumpBy::create(1.0f, Vec2(-200,30), 200, 2),
                                                                                       NULL);
                                                       this->getChildByName("UnityChan")->runAction(action);
                                                   });
    auto initItem = MenuItemImage::create(
                                             "btn_init.png",
                                             "",
                                             [this](Ref* p){
                                                 auto unityChan = static_cast<Sprite*>(this->getChildByName("UnityChan"));
                                                 unityChan->stopAllActions();
                                                 unityChan->setScale(2);
                                                 unityChan->setPosition(480, 200);
                                                 unityChan->setRotation(0);
                                                 unityChan->setOpacity(255);
                                                 unityChan->setColor(Color3B::WHITE);
                                                 unityChan->setSkewX(0);
                                                 unityChan->setSkewY(0);
                                                 char imagePath[256] = {0};
                                                 snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "footwork", 0);
                                                 unityChan->setSpriteFrame(imagePath);
                                             });
    sequenceItem->setPosition(btnX1, btnY3);
    spawnItem->setPosition(btnX2, btnY3);
    repeatItem->setPosition(btnX3, btnY3);
    repeatForeverItem->setPosition(btnX4, btnY3);
    delayTimeItem->setPosition(btnX5, btnY3);
    initItem->setPosition(btnX1, btnY5);
//    runItem->setPosition(btnX7, btnY4);
    
    menu->addChild(sequenceItem);
    menu->addChild(spawnItem);
    menu->addChild(repeatItem);
    menu->addChild(repeatForeverItem);
    menu->addChild(delayTimeItem);
    menu->addChild(initItem);
//    menu->addChild(runItem);

    
    // ここからフレームアニメーション
    
    
    auto footworkItem = MenuItemImage::create(
                                              "btn_footwork.png",
                                              "",
                                              [this](Ref* p){
                                                  auto animation = Animation::create();
                                                  char imagePath[256] = {0};
                                                  auto frameCache = SpriteFrameCache::getInstance();
                                                  for (int i = 0; i < 3; ++i) {
                                                      snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "footwork", i);
                                                      animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                  }
                                                  animation->setDelayPerUnit(0.3f);
                                                  animation->setLoops(3);
                                                  animation->setRestoreOriginalFrame(false);
                                                  this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                              });
    auto jumpUpItem = MenuItemImage::create(
                                              "btn_jump_up.png",
                                              "",
                                              [this](Ref* p){
                                                  auto animation = Animation::create();
                                                  char imagePath[256] = {0};
                                                  auto frameCache = SpriteFrameCache::getInstance();
                                                  for (int i = 0; i < 2; ++i) {
                                                      snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "jump_up", i);
                                                      animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                  }
                                                  animation->setDelayPerUnit(0.3f);
                                                  animation->setLoops(3);
                                                  animation->setRestoreOriginalFrame(false);
                                                  this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                              });
    auto jumpTopItem = MenuItemImage::create(
                                            "btn_jump_top.png",
                                            "",
                                            [this](Ref* p){
                                                auto animation = Animation::create();
                                                char imagePath[256] = {0};
                                                auto frameCache = SpriteFrameCache::getInstance();
                                                for (int i = 0; i < 3; ++i) {
                                                    snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "jump_top", i);
                                                    animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                }
                                                animation->setDelayPerUnit(0.4f);
                                                animation->setLoops(1);
                                                animation->setRestoreOriginalFrame(false);
                                                this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                            });
    auto jumpDownItem = MenuItemImage::create(
                                            "btn_jump_down.png",
                                            "",
                                            [this](Ref* p){
                                                auto animation = Animation::create();
                                                char imagePath[256] = {0};
                                                auto frameCache = SpriteFrameCache::getInstance();
                                                for (int i = 0; i < 2; ++i) {
                                                    snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "jump_down", i);
                                                    animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                }
                                                animation->setDelayPerUnit(0.3f);
                                                animation->setLoops(3);
                                                animation->setRestoreOriginalFrame(false);
                                                this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                            });
    auto damage1Item = MenuItemImage::create(
                                              "btn_damage1.png",
                                              "",
                                              [this](Ref* p){
                                                  auto animation = Animation::create();
                                                  char imagePath[256] = {0};
                                                  auto frameCache = SpriteFrameCache::getInstance();
                                                  for (int i = 0; i < 1; ++i) {
                                                      snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "damage1", i);
                                                      animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                  }
                                                  animation->setDelayPerUnit(0.5f);
                                                  animation->setLoops(0);
                                                  animation->setRestoreOriginalFrame(false);
                                                  this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                              });
    auto damage2Item = MenuItemImage::create(
                                             "btn_damage2.png",
                                             "",
                                             [this](Ref* p){
                                                 auto animation = Animation::create();
                                                 char imagePath[256] = {0};
                                                 auto frameCache = SpriteFrameCache::getInstance();
                                                 for (int i = 0; i < 1; ++i) {
                                                     snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "damage2", i);
                                                     animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                 }
                                                 animation->setDelayPerUnit(0.5f);
                                                 animation->setLoops(0);
                                                 animation->setRestoreOriginalFrame(false);
                                                 this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                             });
    auto runItem = MenuItemImage::create(
                                              "btn_run.png",
                                              "",
                                              [this](Ref* p){
                                                  auto animation = Animation::create();
                                                  char imagePath[256] = {0};
                                                  auto frameCache = SpriteFrameCache::getInstance();
                                                  for (int i = 0; i < 8; ++i) {
                                                      snprintf(imagePath, sizeof(imagePath), "UnityChan_%s_%d.png", "run", i);
                                                      animation->addSpriteFrame(frameCache->getSpriteFrameByName(imagePath));
                                                  }
                                                  animation->setDelayPerUnit(0.3f);
                                                  animation->setLoops(3);
                                                  animation->setRestoreOriginalFrame(false);
                                                  this->getChildByName("UnityChan")->runAction(Animate::create(animation));
                                              });
    
    footworkItem->setPosition(btnX1, btnY4);
    jumpUpItem->setPosition(btnX2, btnY4);
    jumpTopItem->setPosition(btnX3, btnY4);
    jumpDownItem->setPosition(btnX4, btnY4);
    damage1Item->setPosition(btnX5, btnY4);
    damage2Item->setPosition(btnX6, btnY4);
    runItem->setPosition(btnX7, btnY4);
    
    menu->addChild(footworkItem);
    menu->addChild(jumpUpItem);
    menu->addChild(jumpTopItem);
    menu->addChild(jumpDownItem);
    menu->addChild(damage1Item);
    menu->addChild(damage2Item);
    menu->addChild(runItem);
    
    return true;
}
//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    CCLOG("閉じるボタンが押された");
//}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
