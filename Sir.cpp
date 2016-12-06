#include "Sir.h"
#include "Settings.h"
#include <iostream>

using namespace std;

Sir::Sir()
{
    xLimit = 650.f;
    health = 100;
    isJumping = false;
    reachedScreenLimit = false;
    isFalling = false;
    AnimSprite.setFrameTime(sf::seconds(0.1f));
    AnimSprite.setLooped(true);
    Attack = 10;
//    CurAttackX = 0;
    //AnimSprite.play();
    JumpSpeed = -39.f;
    Speed = 250.f;
    texArray[0].loadFromFile("images/walkr.png");
    Animations["MoveRight"] = Animation();
    Animations["MoveRight"].setSpriteSheet(texArray[0]);
    for(int i=0;i<3;++i)
    {
        Animations["MoveRight"].addFrame(sf::IntRect(98*i,0,98,130));
    }
     //AnimSprite.setPosition(100.f,400.f);
    texArray[1].loadFromFile("images/idle.png");
    Animations["Idle"] = Animation();
    Animations["Idle"].setSpriteSheet(texArray[1]);
    for(int i=0;i<2;++i)
    {
        Animations["Idle"].addFrame(sf::IntRect(98*i,0,98,130));
    }
    texArray[2].loadFromFile("images/walkl.png");
    Animations["MoveLeft"] = Animation();
    Animations["MoveLeft"].setSpriteSheet(texArray[2]);
    for(int i=0;i<3;++i)
    {
        Animations["MoveLeft"].addFrame(sf::IntRect(98*i,0,98,130));
    }
    texArray[3].loadFromFile("images/shadow.png");
    Shadow.setTexture(texArray[3]);
    AnimSprite.setPosition(100.f,400.f);
    //AnimSprite.setScale(2.f,2.f);
    //AnimSprite.setAnimation(Animations["MoveRight"]);
}

void Sir::update(sf::Time frameTime,vector<Platform*> pList)
{
    isIdle = true;
    //cout<<AnimSprite.getPosition().y<<endl;
    AnimSprite.setFrameTime(sf::seconds(0.1f));

    bool isPlatformBelow = false;
    sf::Vector2f curPos = AnimSprite.getPosition();
    Platform* pl;
    for(vector<Platform*>::iterator it=pList.begin();it!=pList.end();++it)
    {
        pl = *it;
        if(pl->getPosition().y>curPos.y+100) //if current Position higher than platform
        {
            if(curPos.x+70>=pl->getPosition().x && curPos.x < pl->getPosition().x + pl->getLength())
            {
                isPlatformBelow = true;
                //cout<<pl->getPosition().x<<" "<<curPos.x<<endl;
                break;
            }
        }
    }

    if(isJumping)
    {
        if(isPlatformBelow)
        {
            inY = pl->getPosition().y - AnimSprite.getLocalBounds().height;
        }
        Yvel = Yvel+GRAVITY;
        if(Yvel>=-JumpSpeed)
        {
            AnimSprite.setPosition(sf::Vector2f(AnimSprite.getPosition().x,inY));
            isJumping = false;
        }
        else
        {
            if(AnimSprite.getPosition().y+ Yvel*0.8>inY)
            {
            AnimSprite.setPosition(sf::Vector2f(AnimSprite.getPosition().x,inY));
            isJumping = false;
            }else
            AnimSprite.setPosition(sf::Vector2f(AnimSprite.getPosition().x,AnimSprite.getPosition().y+ Yvel*0.8));
            isIdle = false;
        }
    }
    if(!isJumping && !isPlatformBelow && AnimSprite.getPosition().y<400.f)
    {
        isFalling = true;
    }
    if(isFalling)
    {
        if(AnimSprite.getPosition().y+10.f>400.f)
        {
            AnimSprite.setPosition(sf::Vector2f(AnimSprite.getPosition().x,400.f));
            isFalling = false;
        }
        else
        AnimSprite.setPosition(sf::Vector2f(AnimSprite.getPosition().x,AnimSprite.getPosition().y+ 10.f));
    }
   /* if(isAttacking)
    {
        if(CurAttackX==AnimSprite.getLocalBounds().width+AttackX)
        {
            isAttacking = false;
        }
        if(CurAttackX+1.f>(AnimSprite.getLocalBounds().width+AttackX))
        {
            CurAttackX = AnimSprite.getLocalBounds().width+AttackX;
        }
        else
        {
            CurAttackX +=1.f;
        }
    }*/

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        AnimSprite.play(Animations["MoveRight"]);
        AnimSprite.move(Speed*frameTime.asSeconds(),0);
        Direction = RIGHT;
        isWalking = true;
        isIdle = false;
        //Yvel = -20.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        AnimSprite.play(Animations["MoveLeft"]);
        Direction = LEFT;
        AnimSprite.move(-Speed*frameTime.asSeconds(),0);
        isIdle = false;
        //Yvel = -20.f;
        //AnimSprite.setPosition(AnimSprite.getPosition().x-10,AnimSprite.getPosition().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if(!isAttacking)
        {
            isAttacking = true;
        }
        isIdle = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(!isJumping)
        {
            isJumping = true;
            Yvel = JumpSpeed;
            inY = AnimSprite.getPosition().y;
            AnimSprite.play(Animations["Idle"]);
            //checkCollision(*this);
        }
        isIdle = false;
    }
    if(isIdle)
    {
        AnimSprite.setFrameTime(sf::seconds(0.2f));
        AnimSprite.play(Animations["Idle"]);
    }
    updateShadow();
    AnimSprite.update(frameTime);
}

void Sir::updateShadow()
{
    float x = AnimSprite.getPosition().x,y;
    if(isJumping)
        y = inY;
    else y = AnimSprite.getPosition().y;
    if(Direction==RIGHT)
    {
        y+=38;
        x-=80;
    }
    else
    {
        y+=38;
        x-=60;
    }
    Shadow.setPosition(x,y);

}

bool Sir::checkCollision(Actor &ac)
{
    sf::FloatRect CurBox = sf::FloatRect(AnimSprite.getPosition().x,AnimSprite.getPosition().y, AnimSprite.getPosition().x + AnimSprite.getLocalBounds().width, AnimSprite.getPosition().y + AnimSprite.getLocalBounds().height);
    sf::FloatRect AcBox = sf::FloatRect(ac.getSprite().getPosition().x,ac.getSprite().getPosition().y, ac.getSprite().getPosition().x + ac.getSprite().getLocalBounds().width, ac.getSprite().getPosition().y + AnimSprite.getLocalBounds().height);
    cout<<CurBox.left<<" "<<CurBox.width<<endl;
    if(this->isAttacking)
    {
        if(Direction==RIGHT)
        CurBox.width += 1.f;//;CurAttackX;
        /***Check overlap between AcBox and CurBox**/
        sf::Vector2f Pos(CurBox.left,CurBox.top);
        sf::Vector2f Size(CurBox.width,CurBox.height);
        sf::Vector2f aPos(AcBox.left,AcBox.top);
        sf::Vector2f aSize(AcBox.width,AcBox.height);
        if(Size.x>aPos.x){
             // if(Pos.y<=aPos.y && Size.y<=aSize.y || Pos.y>=aPos.y && Size.y>=aSize.y)

        }

    }
}
