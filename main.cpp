#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_mixer.h>
#define pi2 1.57

using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian);

void rectAli(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian, SDL_Rect rectangle);

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);

void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int widht, int R, int G, int B );

void texture(SDL_Renderer *m_renderer, int xp, int yp, string addressOfImage, int width, int height);

void shoot();

void InitialSetup();

void r();

void def();

void l();

void jumpup();

void inball();

void checkmove();

void intersect();

void punch();

void fire();

void triple();

void checkend();
//menu code
void init1();
void menu();
void defm1();
void text1();
void text2();
void player1text();
void player2text();
void get_xy_mouse();
void ballmenu();
void ballmenu2();
void check_mousemovement();
void fieldmenu();
void historymenu();
void playermenu();
void checkclick();
void leaguemenu();
bool btn_clicked(int index, int mouse_x, int mouse_y);
//menu var
//first while:
string player1=" ",player2=" ";
vector<string> leaderboard;
int mx, my, nx, ny, x, y;
int ph1, ph2;
int ballnumber, fieldnumber, music = 0;
int xp=100, yp=200, xp2=1000, x_backm=50, y_backm=50, x_play=550, y_play=599, x_league= 100, y_league= 599,x_ballm= 100, y_ballm= 500,x_ground=1110, y_ground=599,x_home=1110, y_home=500;
int r1=255, g1=255, b1=255, r2=255, g2=255, b2=255, rc1=255, gc1=255, bc1=255, rc2=255, gc2=255, bc2=255;
int flag=1, flag2=1, flag3=1, flag4=1, flag5=0, flagn, flag6, flag9=0, flag7=0, flag8;
int ballnum;

int conditionn=0;

const char * text11 =" <<time limit>> ";
const char * text22 =" <<goal limit>> ";

//second while:
int flag1,x_mouse,y_mouse;

//history
string played1;
string played2;
string point1;
string point2;

//menu:
SDL_Texture* backb;
SDL_Texture* backm;
SDL_Texture* league;
SDL_Texture* ballm;
SDL_Texture* ground;
SDL_Texture* home;
SDL_Texture* history;
SDL_Texture* play1;
SDL_Texture* player;
SDL_Texture* note_icon;
SDL_Texture* note;
//home menu:
SDL_Texture* settingb;
SDL_Texture* music1;
SDL_Texture* music2;

//ball menu:
SDL_Texture* ballback;
SDL_Texture* ball1;
SDL_Texture* ball2;
SDL_Texture* ball3;
SDL_Texture* ball4;
SDL_Texture* ball5;
SDL_Texture* ball6;
SDL_Texture* ball7;
SDL_Texture* ball8;

//field menu:
SDL_Texture* fieldback;
SDL_Texture* field1;
SDL_Texture* field2;
SDL_Texture* field3;
SDL_Texture* field4;
SDL_Texture* field5;

//league menu:
SDL_Texture* playerback2;
SDL_Texture* playerback3;
SDL_Texture* table;

//history menu:
SDL_Texture* history1;

//player menu:
SDL_Texture* playerback4;
SDL_Texture* green;
SDL_Texture* blue;
SDL_Texture* yellow;
SDL_Texture* red;
SDL_Texture* perple;
SDL_Texture* greenc;
SDL_Texture* bluec;
SDL_Texture* yellowc;
SDL_Texture* redc;
SDL_Texture* perplec;
SDL_Texture* halfm;
SDL_Texture* shoem;
SDL_Texture* shoe2m;


SDL_Event* e = new SDL_Event();
SDL_Event* p = new SDL_Event();


Mix_Music *backsound;
Mix_Music *GameSound;
Mix_Music *footbalista;
Mix_Chunk *gun;
Mix_Chunk *shootsound;
Mix_Chunk *click;
Mix_Chunk *crowd;

//game var
int W = 700;

int L = 1280;

double x_ball = 640, y_ball = 500, y0=560, x_player1 = 300, y_player1 = 572;

double x_player2 = 980, y_player2 = 572, l_player2 = 80, w_player2 = 51;

double x_player2c1 = x_player2 + 70, x_player2c2 = x_player2 - 70, y_player2c1 = y_player2, y_player2c2 = y_player2;

double l_player1 = 80, w_player1 = 51, r_ball = 50, y_grass = 500;

double x_goal = -50, y_goal = W-400, x_goal2 = 1150;

double vy_player1, vx_player1, vy_player2=0, vx_player2=0;

double tan1, sin1, cos1;

double acce = .07, dx = 0, dy = 0,zarib=1,passes;

double elapsedTime, etime;

bool shot = 0, rit = 0, leftmove = 0, jump = 1,leftmove2 = 0,rit2 = 0, endgame = 0, res = 0, isran = 0, trip = 0;

bool isgoal = 0, jump2 = 1, isgoal2 = 0, punchdet = 0, indet = 0, fireball = 0, isfireball = 0, menurun = 1, goalin = 0;

bool notgoal = 0, powerbar = 0;

int player_2_goals = 0, player_1_goals = 0;

double power1L = 0, power2L = 0, powplus1 = 1, powplus2 = 1;

uint32_t startTime;

uint32_t punchtime;

uint32_t intime;

uint32_t firetime;

uint32_t restime;

uint32_t triptime;

stringstream timeText;

SDL_Window* m_window;
SDL_Renderer* m_renderer;
SDL_Texture* ball;
SDL_Texture* background;
SDL_Texture* half;
SDL_Texture* shoe;
SDL_Texture* shoe2;
SDL_Texture* goal;
SDL_Texture* goal2;
SDL_Texture* scoreboard;
SDL_Texture* goaltext;
SDL_Texture* punchgif;
SDL_Texture* hole;
SDL_Texture* sec;
SDL_Texture* goals1;
SDL_Texture* goals2;
SDL_Texture* pauseicon;
SDL_Texture* gameover;
SDL_Texture* ppmenu;
SDL_Texture* pmenu;
SDL_Texture* resume;
SDL_Texture* quit;
SDL_Texture* re;
SDL_Event* event;

TTF_Font * font;

int main(int argc, char* argv[])
{

    init1();
    SDL_StartTextInput();
    SDL_Event* click = new SDL_Event();

    ifstream input;
    string s;
    input.open("input.txt");

    while(input)
    {
        getline(input, s);
        leaderboard.push_back(s);
    }
    leaderboard.pop_back();
    input.close();
    //Mix_PlayMusic(GameSound,-1);

    //Mix_PlayMusic(footbalista,-1);
    //Mix_PlayMusic(GameSound,-1);
    while(menurun)
    {

        menu();
        if(menurun==0)
            break;

    }
    //Mix_FreeMusic(GameSound);

    SDL_DestroyWindow(m_window);
    startTime = SDL_GetTicks();



//    if(music==1)
//        Mix_PlayMusic(backsound,-1);
//
//    else
//        Mix_PlayMusic(footbalista,-1);

    InitialSetup();
    while(true)
    {

        int mx, my;
        Uint32 button;
        button = SDL_GetMouseState(&mx, &my);
        //cout<<my<<endl;
        if(y_player1>=570)
            vx_player1=0;

        if(y_player2>=570)
            vx_player2=0;

        if(punchdet)
            punch();

        if(indet)
            inball();

        if(isfireball)
            fire();

        if(trip)
            triple();

        def();
        if(endgame)
        {
            SDL_RenderClear(m_renderer);
            SDL_Delay(2000);
            def();
            SDL_Rect gameoverrect = {L/2-250, W/2-300, 500, 500};
            SDL_RenderCopy(m_renderer, gameover, NULL, &gameoverrect);
            SDL_RenderPresent(m_renderer);
            SDL_Delay(2000);


            bool found=false;

            for(int i=0; i<leaderboard.size(); i++)
            {
                if(leaderboard[i]==player1)
                {
                    ph1=i+1;
                    found=true;
                    int emtiaz1 = stoi(leaderboard[ph1]);
                    emtiaz1+=10*player_2_goals;
                    leaderboard[ph1]=to_string(emtiaz1);
                    break;
                }
            }
            if(!found)
            {
                leaderboard.push_back(player1);
                int point1=0;
                point1+=10*player_2_goals;
                string point1s=to_string(point1);
                leaderboard.push_back(point1s);
            }

            bool found1=false;

            for(int i=0; i<leaderboard.size(); i++)
            {
                if(leaderboard[i]==player2)
                {
                    ph2=i+1;
                    found1=true;
                    int emtiaz2 = stoi(leaderboard[ph2]);
                    emtiaz2+=10*player_1_goals;
                    leaderboard[ph2]= to_string(emtiaz2);
                    break;
                }
            }
            if(!found1)
            {
                leaderboard.push_back(player2);
                int point2=0;
                point2+=10*player_1_goals;
                string point2s=to_string(point2);
                leaderboard.push_back(point2s);
            }

            ofstream output;
            output.open("input.txt");
            for(int i=0; i<leaderboard.size(); i++)
            {
                output << leaderboard[i] << endl;
            }

            break;

        }



    }


}
void init1()
{
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Init( SDL_flags );
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    GameSound = Mix_LoadMUS("back.mp3");
    footbalista = Mix_LoadMUS("Football Bartar 98.mp3");
    backsound = Mix_LoadMUS("DOVER  VINO - HYDRA (Original Mix).mp3");
    crowd = Mix_LoadWAV("mixkit-crowd-at-the-stadium-2111.wav");
    TTF_Init();
    SDL_CreateWindowAndRenderer( 1280, 800, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    font = TTF_OpenFont("fonts//Demo_ConeriaScript.ttf", 400);
//    cout << SDL_GetError() << endl;
    background = IMG_LoadTexture(m_renderer, "image//backm2.jpg");
    ball = IMG_LoadTexture(m_renderer, "image//ball.png");
    shoem= IMG_LoadTexture(m_renderer, "image//shoe2.png");
    shoe2m= IMG_LoadTexture(m_renderer, "image//shoe.png");
    halfm= IMG_LoadTexture(m_renderer, "image//half.png");



    backm= IMG_LoadTexture(m_renderer, "image//backm.jpg");
    note_icon= IMG_LoadTexture(m_renderer, "image//note icon.png");
    league= IMG_LoadTexture(m_renderer, "image//league.png");
    ballm= IMG_LoadTexture(m_renderer, "image//ballm.png");
    ground= IMG_LoadTexture(m_renderer, "image//ground.png");
    home= IMG_LoadTexture(m_renderer, "image//home.png");
    history= IMG_LoadTexture(m_renderer, "image//history.png");
    play1= IMG_LoadTexture(m_renderer, "image//play1.png");
    backb= IMG_LoadTexture(m_renderer, "image//back.png");
    player= IMG_LoadTexture(m_renderer, "image//player.png");
//home menu:
    settingb= IMG_LoadTexture(m_renderer, "image//setting.jpg");
    music1= IMG_LoadTexture(m_renderer, "image//music1.png");
    music2= IMG_LoadTexture(m_renderer, "image//music2.png");

    //ball menu:
    ballback= IMG_LoadTexture(m_renderer, "image//ballback.png");
    ball1= IMG_LoadTexture(m_renderer, "image//ball1.png");
    ball2= IMG_LoadTexture(m_renderer, "image//ball2.png");
    ball3= IMG_LoadTexture(m_renderer, "image//ball3.png");
    ball4= IMG_LoadTexture(m_renderer, "image//ball4.png");
    ball5= IMG_LoadTexture(m_renderer, "image//ball5.png");
    ball6= IMG_LoadTexture(m_renderer, "image//ball6.png");
    ball7= IMG_LoadTexture(m_renderer, "image//ball7.png");
    ball8= IMG_LoadTexture(m_renderer, "image//ball8.png");

    //field menu:
    fieldback= IMG_LoadTexture(m_renderer, "image//fieldback.png");
    field1= IMG_LoadTexture(m_renderer, "image//field1.jpg");
    field2= IMG_LoadTexture(m_renderer, "image//field2.jpg");
    field3= IMG_LoadTexture(m_renderer, "image//field3.jpg");
    field4= IMG_LoadTexture(m_renderer, "image//field4.jpg");
    field5= IMG_LoadTexture(m_renderer, "image//field5.jpg");

    //league menu:
    playerback3= IMG_LoadTexture(m_renderer, "image//playerback3.png");
    playerback2= IMG_LoadTexture(m_renderer, "image//playerback2.png");
    table= IMG_LoadTexture(m_renderer, "image//table.png");

    //history menu:
    history1= IMG_LoadTexture(m_renderer, "image//history1.png");

    //player menu:
    playerback4= IMG_LoadTexture(m_renderer, "image//playerback4.jpg");
    perple= IMG_LoadTexture(m_renderer, "image//perple.png");
    perplec= IMG_LoadTexture(m_renderer, "image//perplec.png");
    green= IMG_LoadTexture(m_renderer, "image//green.png");
    greenc= IMG_LoadTexture(m_renderer, "image//greenc.png");
    red= IMG_LoadTexture(m_renderer, "image//red.png");
    redc= IMG_LoadTexture(m_renderer, "image//redc.png");
    yellow= IMG_LoadTexture(m_renderer, "image//yellow.png");
    yellowc= IMG_LoadTexture(m_renderer, "image//yellowc.png");
    blue= IMG_LoadTexture(m_renderer, "image//blue.png");
    bluec= IMG_LoadTexture(m_renderer, "image//bluec.png");

    //note icon:
    note= IMG_LoadTexture(m_renderer, "image//note.jpg");
}
void InitialSetup()
{

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Init( SDL_flags );
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    GameSound = Mix_LoadMUS("back.mp3");
    backsound = Mix_LoadMUS("DOVER  VINO - HYDRA (Original Mix).mp3");
    footbalista = Mix_LoadMUS("Football Bartar 98.mp3");
    gun=Mix_LoadWAV("shot.wav");
    shootsound=Mix_LoadWAV("mixkit-soccer-ball-quick-kick-2108.wav");
    crowd = Mix_LoadWAV("mixkit-crowd-at-the-stadium-2111.wav");
    TTF_Init();
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    font = TTF_OpenFont("fonts//Demo_ConeriaScript.ttf", 400);
    background = IMG_LoadTexture(m_renderer, "image//backm2.jpg");
    ball = IMG_LoadTexture(m_renderer, "image//ball.png");
    half = IMG_LoadTexture(m_renderer, "image//half.png");
    shoe = IMG_LoadTexture(m_renderer, "image//shoe.png");
    shoe2 = IMG_LoadTexture(m_renderer, "image//shoe2.png");
    goal = IMG_LoadTexture(m_renderer, "image//goal.png");
    goal2 = IMG_LoadTexture(m_renderer, "image//goal2.png");
    goaltext = IMG_LoadTexture(m_renderer, "image//goaltext.png");
    scoreboard = IMG_LoadTexture(m_renderer, "image//scoreboard.png");
    punchgif = IMG_LoadTexture(m_renderer, "image//birds.gif");
    hole = IMG_LoadTexture(m_renderer, "image//hole.png");
    gameover = IMG_LoadTexture(m_renderer, "image//gameover.png");
    backm= IMG_LoadTexture(m_renderer, "image//backm.jpg");
    league= IMG_LoadTexture(m_renderer, "image//league.png");
    ballm= IMG_LoadTexture(m_renderer, "image//ballm.png");
    ground= IMG_LoadTexture(m_renderer, "image//ground.png");
    home= IMG_LoadTexture(m_renderer, "image//home.png");
    history= IMG_LoadTexture(m_renderer, "image//history.png");
    play1= IMG_LoadTexture(m_renderer, "image//play1.png");
    backb= IMG_LoadTexture(m_renderer, "image//back.png");
    player= IMG_LoadTexture(m_renderer, "image//player.png");
    pauseicon = IMG_LoadTexture(m_renderer, "image//pauseicon.png");
    ppmenu = IMG_LoadTexture(m_renderer, "image//ppmenu.jpg");
    pmenu = IMG_LoadTexture(m_renderer, "image//pmenu.png");
    resume = IMG_LoadTexture(m_renderer, "image//resume.png");
    quit = IMG_LoadTexture(m_renderer, "image//quit.png");
    re = IMG_LoadTexture(m_renderer, "image//reset.png");

    //ball menu:
    ballback= IMG_LoadTexture(m_renderer, "image//ballback.png");
    ball1= IMG_LoadTexture(m_renderer, "image//ball1.png");
    ball2= IMG_LoadTexture(m_renderer, "image//ball2.png");
    ball3= IMG_LoadTexture(m_renderer, "image//ball3.png");
    ball4= IMG_LoadTexture(m_renderer, "image//ball4.png");
    ball5= IMG_LoadTexture(m_renderer, "image//ball5.png");
    ball6= IMG_LoadTexture(m_renderer, "image//ball6.png");
    ball7= IMG_LoadTexture(m_renderer, "image//ball7.png");
    ball8= IMG_LoadTexture(m_renderer, "image//ball8.png");

    //field menu:
    fieldback= IMG_LoadTexture(m_renderer, "image//fieldback.png");
    field1= IMG_LoadTexture(m_renderer, "image//field1.jpg");
    field2= IMG_LoadTexture(m_renderer, "image//field2.jpg");
    field3= IMG_LoadTexture(m_renderer, "image//field3.jpg");
    field4= IMG_LoadTexture(m_renderer, "image//field4.jpg");
    field5= IMG_LoadTexture(m_renderer, "image//field5.jpg");

    //league menu:
    playerback3= IMG_LoadTexture(m_renderer, "image//playerback3.png");
    playerback2= IMG_LoadTexture(m_renderer, "image//playerback2.png");
    table= IMG_LoadTexture(m_renderer, "image//table.png");

    //history menu:
    history1= IMG_LoadTexture(m_renderer, "image//history1.png");

    //player menu:
    playerback4= IMG_LoadTexture(m_renderer, "image//playerback4.jpg");
    perple= IMG_LoadTexture(m_renderer, "image//perple.png");
    perplec= IMG_LoadTexture(m_renderer, "image//perplec.png");
    green= IMG_LoadTexture(m_renderer, "image//green.png");
    greenc= IMG_LoadTexture(m_renderer, "image//greenc.png");
    red= IMG_LoadTexture(m_renderer, "image//red.png");
    redc= IMG_LoadTexture(m_renderer, "image//redc.png");
    yellow= IMG_LoadTexture(m_renderer, "image//yellow.png");
    yellowc= IMG_LoadTexture(m_renderer, "image//yellowc.png");
    blue= IMG_LoadTexture(m_renderer, "image//blue.png");
    bluec= IMG_LoadTexture(m_renderer, "image//bluec.png");

}


void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta,int widht, int R, int G, int B )

{

    int x_2 = x_1 + L*cos(theta);

    int y_2 = y_1 - L*sin(theta);


    thickLineRGBA(Renderer,x_1,y_1,x_2,y_2,widht,R,G,B,255);




}

void rectAli(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian, SDL_Rect rectangle)

{


    rectangle.x = x;

    rectangle.y = y;

    rectangle.w = w;

    rectangle.h = h;


    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);

    if (fill_boolian==1)

        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_Rect dstrect = {x_ball, y_ball, r_ball, r_ball};



    SDL_RenderDrawRect(Renderer, &rectangle);



}
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B,fill_boolian);
    SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
    // SDL_RenderPresent(Renderer);
}
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)

{

    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);

    if(fill_boolian==0)

        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);


}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)

{

    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );

    SDL_RenderClear( Renderer );





}

void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
    int n = addressOfImage.length();
    char char_array[n+1];
    strcpy(char_array, addressOfImage.c_str());
    SDL_Texture *myTexture;
    myTexture = IMG_LoadTexture( m_renderer, char_array);
    int w1, h1;
    SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
    SDL_Rect texr1;
    texr1.x = xp;
    texr1.y = yp;
    texr1.w = width;
    texr1.h = height;
    SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
    SDL_DestroyTexture(myTexture);
}


void shoot()
{
    //isfireball = 0;
    isran = 0;

    if(y_ball+r_ball>y_player1&&y_ball+r_ball<y_player1+l_player1+20&&y_player1<560&&abs(x_ball-x_player1)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);
        dx=-5;
        dy=-5;
    }

    if(y_ball+r_ball>y_player2&&y_ball+r_ball<y_player2+l_player1+20&&y_player2<560&&abs(x_ball-x_player2)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);

        dx=5;
        dy=-5;
    }
    if(y_ball+r_ball>690&&y_ball+r_ball<700&&abs(x_ball-x_player1)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);
        if(isfireball)
        {
            dx=10;
            dy=5;
        }
        else
        {
            dx=5;
            dy=2;
        }
    }
    if(y_ball+r_ball>690&&y_ball+r_ball<700&&abs(x_ball-x_player2)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);
        dx=-5;
        dy=2;
    }
    if(y_ball+r_ball>670&&y_ball+r_ball<690&&abs(x_ball-x_player1)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);
        if(isfireball)
        {
            dx=10;
            dy=5;

        }
        else
        {
            dx=5;
            dy=5;
        }
    }
    if(y_ball+r_ball>670&&y_ball+r_ball<690&&abs(x_ball-x_player2)<w_player1+30)
    {
        Mix_PlayChannel(-1,shootsound,0);

        dx=-5;
        dy=5;

    }

    if(trip)
    {
        if(y_ball+r_ball>670&&y_ball+r_ball<690&&abs(x_ball-x_player2c2)<w_player2+30)
        {
            Mix_PlayChannel(-1,shootsound,0);

            dx=-5;
            dy=5;
        }
        if(y_ball+r_ball>690&&y_ball+r_ball<700&&abs(x_ball-x_player2c2)<w_player2+30)
        {
            Mix_PlayChannel(-1,shootsound,0);
            dx=-5;
            dy=2;
        }

    }


    shot = 0;
}
void def()
{
    intersect();
    SDL_Rect shoecor2 = {x_player1 + 25, y_player1 + l_player1 + 32, 50, 20};
    SDL_Rect shoecor = {x_player1 + 7, y_player1 + l_player1 + 32, 50, 20};
    SDL_Rect shoecor3 = {x_player2 - 23, y_player2 + l_player2 + 32, 50, 20};
    SDL_Rect shoecor4 = {x_player2 - 5, y_player2 + l_player2 + 32, 50, 20};
    SDL_Rect rectbody1 = {x_player1, y_player1, w_player1, l_player1};
    SDL_Rect rectbody2 = {x_player2, y_player2, w_player2, l_player2};
    SDL_Rect goalcor = {x_goal, y_goal, 200, 400};
    SDL_Rect goalcor2 = {x_goal2, y_goal, 200, 400};
    SDL_Rect ballrect = {x_ball, y_ball, r_ball, r_ball};
    SDL_Rect halfrect1 = {x_player1, y_player1 + l_player1, 52, 30};
    SDL_Rect halfrect2 = {x_player2, y_player2 + l_player2, 52, 30};
    SDL_Rect star = {x_player2, y_player2 - 100, 52, 30};
    SDL_Rect scoreboardrect = {450, 30, 400, 100};
    SDL_Rect holerect = {x_player2  + 25, y_player2 - 39, 30, 30};
    SDL_Rect goaltextrect = {L/2-250, W/2-300, 500, 500};
    SDL_Rect pauserect = {L/2-15, 80, 50, 50};


    if (fieldnumber==1)
        SDL_RenderCopy(m_renderer, field1, NULL, NULL);
    else if (fieldnumber==2)
        SDL_RenderCopy(m_renderer, field2, NULL, NULL);
    else if (fieldnumber==3)
        SDL_RenderCopy(m_renderer, field3, NULL, NULL);
    else if (fieldnumber==4)
        SDL_RenderCopy(m_renderer, field4, NULL, NULL);
    else if (fieldnumber==5)
        SDL_RenderCopy(m_renderer, field5, NULL, NULL);

//    cout<<fieldnumber<<endl;
    if(!indet)
    {
        if (ballnumber==1)
            SDL_RenderCopy(m_renderer, ball1, NULL, &ballrect);
        else if (ballnumber==2)
            SDL_RenderCopy(m_renderer, ball2, NULL, &ballrect);
        else if (ballnumber==3)
            SDL_RenderCopy(m_renderer, ball3, NULL, &ballrect);
        else if (ballnumber==4)
            SDL_RenderCopy(m_renderer, ball4, NULL, &ballrect);
        else if (ballnumber==5)
            SDL_RenderCopy(m_renderer, ball5, NULL, &ballrect);
        else if (ballnumber==6)
            SDL_RenderCopy(m_renderer, ball6, NULL, &ballrect);
        else if (ballnumber==7)
            SDL_RenderCopy(m_renderer, ball7, NULL, &ballrect);
        else if (ballnumber==8)
            SDL_RenderCopy(m_renderer, ball8, NULL, &ballrect);
    }

    SDL_RenderCopy(m_renderer, goal, NULL, &goalcor);
    SDL_RenderCopy(m_renderer, goal2, NULL, &goalcor2);
    SDL_RenderCopy(m_renderer, scoreboard, NULL, &scoreboardrect);


    if(isgoal||isgoal2)
        SDL_RenderCopy(m_renderer, goaltext, NULL, &goaltextrect);


    rectAli(m_renderer, x_player1, y_player1, w_player1, l_player1, r1, g1, b1, 1,rectbody1);
    rectAli(m_renderer, x_player2, y_player2, w_player2, l_player2, r2, g2, b2, 1,rectbody2);


    ellipse(m_renderer, x_player1  + 25, y_player1 - 39, 39, 39, rc1, gc1, bc1, 1);
    ellipse(m_renderer, x_player2  + 25, y_player2 - 39, 39, 39, rc2, gc2, bc2, 1);


    rect(m_renderer, 20, 20, power1L, 20, 255, 0, 0, 255);
    rect(m_renderer, 1000, 20, power2L, 20, 255, 0, 0, 255);

    SDL_RenderCopy(m_renderer, half, NULL, &halfrect1);
    SDL_RenderCopy(m_renderer, half, NULL, &halfrect2);
    SDL_RenderCopy(m_renderer, shoe, NULL, &shoecor2);
    SDL_RenderCopy(m_renderer, shoe, NULL, &shoecor);
    SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor3);
    SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor4);
    SDL_RenderCopy(m_renderer, pauseicon, NULL, &pauserect);

    if(punchdet&&elapsedTime<1)
        SDL_RenderCopy(m_renderer, hole, NULL, &holerect);

    if(punchdet)
        SDL_RenderCopy(m_renderer, punchgif, NULL, &star);


    if(trip)
    {
        x_player2c1 = x_player2 + 79;
        x_player2c2 = x_player2 - 79;
        y_player2c1 = y_player2;
        y_player2c2 = y_player2;


        SDL_Rect rectbody3 = {x_player2c1, y_player2c1, w_player1, l_player1};
        SDL_Rect rectbody4 = {x_player2c2, y_player2c2, w_player1, l_player1};
        SDL_Rect halfrect3 = {x_player2c1, y_player2c1 + l_player1, 52, 30};
        SDL_Rect halfrect4 = {x_player2c2, y_player2c2 + l_player1, 52, 30};


        rectAli(m_renderer, x_player2c1, y_player2c1, w_player1, l_player1, r2, g2, b2, 1, rectbody3);
        rectAli(m_renderer, x_player2c2, y_player2c2, w_player1, l_player1, r2, g2, b2, 1, rectbody4);
        ellipse(m_renderer, x_player2c1  + 25, y_player2c1 - 39, 39, 39, rc2, gc2, bc2, 1);
        ellipse(m_renderer, x_player2c2  + 25, y_player2c2 - 39, 39, 39, rc2, gc2, bc2, 1);


        SDL_Rect shoecor5 = {x_player2c1 - 23, y_player2c1 + l_player2 + 32, 50, 20};
        SDL_Rect shoecor6 = {x_player2c1 - 5, y_player2c1 + l_player2 + 32, 50, 20};
        SDL_Rect shoecor7 = {x_player2c2 - 23, y_player2c2 + l_player2 + 32, 50, 20};
        SDL_Rect shoecor8 = {x_player2c2 - 5, y_player2c2 + l_player2 + 32, 50, 20};


        SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor6);
        SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor7);
        SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor8);
        SDL_RenderCopy(m_renderer, shoe2, NULL, &shoecor5);
        SDL_RenderCopy(m_renderer, half, NULL, &halfrect3);
        SDL_RenderCopy(m_renderer, half, NULL, &halfrect4);

    }


    x_ball+=dx;
    y_ball+=dy;

    if(abs(dy)>20)
        acce = .3;
    else
        acce = .07;

    if(y_ball<649&&y_ball>=0)
        dy+=acce;

    //acce-= .01;

    if(acce==0)
        acce = .07;

    x_player1+=vx_player1;
    y_player1+=vy_player1;
    x_player2+=vx_player2;
    y_player2+=vy_player2;


    if(y_player1<700)
        vy_player1+=.07;
    if(y_player2<700)
        vy_player2+=.07;

    if(y_player1>571)
    {
        vy_player1 = 0;
        jump = 1;
    }

    if(y_player2>571)
    {
        vy_player2 = 0;
        jump2 = 1;
    }


    timeText.str( "" );
//    cout<<restime<<endl;

//    if(res)
//    {
////        cout<<restime<<endl;
//        passes = (SDL_GetTicks() - restime);
//        // cout<<restime<<endl;
//
//    }
//    else


    if(res)
    {
        passes = (SDL_GetTicks()-restime);
    }
    else
        passes = (SDL_GetTicks() - startTime);
    //cout<<res<<endl;
//    cout<<restime<<endl;
    //cout<<SDL_GetTicks() - startTime<<endl;



    timeText << (passes);

    string s = timeText.str();

    for(int i=0; i<3; i++)
        if(s.size()>0)
            s.pop_back();

    if(s.size()==0)
        s.push_back('0');

    string goal1 = to_string(player_1_goals);
    string goal2 = to_string(player_2_goals);



    textRGBA(m_renderer,635,47,s.c_str(),7,30,255,255,255,255);
    textRGBA(m_renderer,585,47,goal2.c_str(),7,30,255,255,255,255);
    textRGBA(m_renderer,700,47,goal1.c_str(),7,30,255,255,255,255);
    textRGBA(m_renderer,460,40,player1.c_str(),7,30,255,255,255,255);
    textRGBA(m_renderer,780,40,player2.c_str(),7,30,255,255,255,255);


    checkmove();



    if(power1L<200)
        power1L+=powplus1;

    if(power2L<200)
        power2L+=powplus2;

    SDL_Delay(2);

    SDL_RenderPresent(m_renderer);

    if(isgoal||isgoal2)
    {

        SDL_Delay(2000);
        isgoal=0;
        isgoal2=0;
        y_ball = 500;
        x_ball = 640;
        x_player1 = 300;
        x_player2 = 980;
        y_player1 = 572;
        y_player2 = 572;
        dx = 0;
        dy = 0;
        fireball = 0;
        trip = 0;
        indet = 0;
        isran = 0;
    }
    checkend();
}
void r()
{
    if(rit)
    {
        x_player1 += 1;
        rit = 0;
    }
    if(rit2)
    {
        x_player2 += 1;
        rit2 = 0;
    }
}
void l()
{
    if(leftmove)
    {
        x_player1 -= 1;
        leftmove = 0;
    }
    if(leftmove2)
    {
        x_player2 -= 1;
        leftmove2 = 0;
    }
}
void jumpup()
{
    for(int i = 0; i <=5; i++)
    {
        SDL_PumpEvents();
        y_player1 -= i;
        def();
    }
}
void checkmove()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);

    int ran;


    SDL_PollEvent(event);
    if(shot)
        SDL_Delay(.5);


    if(state[SDL_SCANCODE_SPACE])
        shot = 1;

    if(state[SDL_SCANCODE_M]&&!isran&&power2L==200)
    {
        ran = rand()%2;
        isran = 1;
        power2L = 0;
    }

    if(state[SDL_SCANCODE_A])
    {
        x_player1 -= 1;
    }

    if(state[SDL_SCANCODE_J]&&(!punchdet&&!isfireball))
        x_player2 -= 1;

    if(state[SDL_SCANCODE_W]&&jump!=0)
    {
        vy_player1-=5;
        jump = 0;
    }
    if(state[SDL_SCANCODE_I]&&jump2!=0&&(!punchdet&&!isfireball))
    {
        vy_player2-=5;
        jump2 = 0;
    }
    if(state[SDL_SCANCODE_D])
        x_player1 += 1;

//    cout<<fireball<<endl;
    if(state[SDL_SCANCODE_L]&&(!punchdet&&!isfireball))
        x_player2 += 1;

    if(state[SDL_SCANCODE_X])
        shoot();

    if(state[SDL_SCANCODE_U])
        shoot();

    if((state[SDL_SCANCODE_Q]&&!punchdet&&power1L>=200))
    {
        Mix_PlayChannel(-1,gun,0);
        punchtime = SDL_GetTicks();
        punchdet = 1;
        power1L = 0;
        punch();
    }

    if((state[SDL_SCANCODE_Z]&&!indet&&power2L>=200)||(ran==1))
    {
        power2L = 0;
        intime = SDL_GetTicks();
        indet = 1;
        inball();
    }
    if((state[SDL_SCANCODE_P]&&!isfireball))
    {
        fireball = 1;
        isfireball = 1;
        power1L = 0;
    }

    if((state[SDL_SCANCODE_V]&&!trip&&power2L>=200)||(ran==0))
    {
        trip = 1;
        power2L = 0;
        triptime = SDL_GetTicks();
        triple();
    }


    if((state[SDL_SCANCODE_O]&&!goalin))
    {
        player_2_goals++;
        goalin = 1;
    }

    if((state[SDL_SCANCODE_E]&&!powerbar))
    {
        powplus2 = 1;
        powerbar = 1;
    }

    if((state[SDL_SCANCODE_B]&&!notgoal))
    {
        notgoal = 1;
    }

}
void intersect()
{

    Uint32 buttons;

    buttons = SDL_GetMouseState(&mx, &my);
    e->type=0;
    SDL_PumpEvents();
    SDL_PollEvent(e);
    if((mx>=L/2-15)&&(mx<=L/2+35)&&(my>=80)&&(my<=130))
    {

        SDL_PumpEvents();
        if(e->type==SDL_MOUSEBUTTONDOWN)
        {
            SDL_PumpEvents();
            //Mix_PlayChannel(-1,click,0);
            //cout<<mx<<"  "<<my<<endl;
            if(e->button.button==SDL_BUTTON_LEFT)
            {


                cout<<mx<<"  "<<my<<endl;
                while(true)
                {
                    SDL_RenderClear(m_renderer);
                    window_color(m_renderer,255,255,255);
                    //SDL_Rect scoreboardrect = {450, 30, 400, 100};

                    SDL_Rect qrect = {530, 450, 200, 100};
                    SDL_Rect rrecet = {580, 350, 100, 100};
                    SDL_Rect prect = {580, 300, 100, 50};

                    SDL_RenderCopy(m_renderer, ppmenu, NULL, NULL);
                    SDL_RenderCopy(m_renderer, resume, NULL, &prect);
                    SDL_RenderCopy(m_renderer, quit, NULL, &qrect);
                    SDL_RenderCopy(m_renderer, re, NULL, &rrecet);
                    SDL_RenderPresent(m_renderer);
                    Uint32 button;
                    SDL_PumpEvents();
                    button = SDL_GetMouseState(&nx, &ny);
                    e->type=0;
                    SDL_PollEvent(e);

                    if((nx>=584)&&(nx<=673)&&(ny>=300)&&(ny<=338))
                    {
                        e->type=0;
                        SDL_PollEvent(e);
                        if(e->type==SDL_MOUSEBUTTONDOWN)
                        {
                            //Mix_PlayChannel(-1,click,0);

                            //if con
                            if(e->button.button==SDL_BUTTON_LEFT)
                            {
                                SDL_RenderClear(m_renderer);
                                break;
                            }
                        }
                    }


                    if((nx>=600)&&(nx<=658)&&(ny>=372)&&(ny<=428))
                    {
                        e->type=0;
                        SDL_PollEvent(e);
                        if(e->type==SDL_MOUSEBUTTONDOWN)
                        {
                            //Mix_PlayChannel(-1,click,0);
                            if(e->button.button==SDL_BUTTON_LEFT)
                            {
                                res = 1;
                                restime = SDL_GetTicks();
                                isgoal=0;
                                isgoal2=0;
                                player_1_goals = 0;
                                player_2_goals = 0;
                                y_ball = 500;
                                x_ball = 640;
                                x_player1 = 300;
                                x_player2 = 980;
                                y_player1 = 572;
                                y_player2 = 572;
                                dx = 0;
                                dy = 0;
                                fireball = 0;
                                fireball = 0;
                                indet = 0;
                                punchdet = 0;
                                SDL_RenderClear(m_renderer);
                                break;
                            }
                        }
                    }



                    if((nx>=587)&&(nx<=670)&&(ny>=470)&&(ny<=516))
                    {
                        e->type=0;
                        SDL_PollEvent(e);
                        if(e->type==SDL_MOUSEBUTTONDOWN)
                        {
                            //Mix_PlayChannel(-1,click,0);
                            if(e->button.button==SDL_BUTTON_LEFT)
                            {
                                SDL_Quit();
                            }
                        }
                    }


                }

            }
        }
    }
    e->type = 0;
    //cout<<startTime<<endl;



    if(x_ball>=L-r_ball||x_ball<r_ball)
        dx=-dx;


    if((x_ball>=L-r_ball-100&&y_ball<300)||(x_ball<r_ball+100&&y_ball<300))
        dx=-dx;

    if(y_ball>=W-r_ball||y_ball<0)
        dy=-dy;


//    cout<<fireball<<endl;

    if((abs(x_player2-x_ball)<=w_player2+30)&&y_ball>y_player2&&y_ball<y_player2+l_player2&&x_ball<x_player2&&fireball)
    {
        x_player2+=100;
        fireball = 0;
        firetime = SDL_GetTicks();


    }

    if(trip)
        if((abs(x_player2-x_ball)<=w_player2+30)&&y_ball>y_player2&&y_ball<y_player2+l_player2&&x_ball<x_player2&&fireball)
        {
            x_player2+=100;
            fireball = 0;
            firetime = SDL_GetTicks();
        }

    if(trip)
        if((abs(x_player2c2-x_ball)<=w_player2)&&y_ball>y_player2c2&&y_ball<y_player2c2+l_player2+20&&x_ball<x_player2c2)
        {
            x_ball-=10;
            dx=-dx;
        }

    if(trip)
        if((abs(x_player2c1-x_ball)<=r_ball)&&y_ball>y_player2c1&&y_ball<y_player2c2+l_player2+20&&x_ball>x_player2c1)
        {
            x_ball+=10;
            dx=-dx;
        }


    if((abs(x_player1-x_ball)<=w_player1)&&y_ball>y_player1&&y_ball<y_player1+l_player1+20&&x_ball>x_player1)
    {
        x_ball+=10;

        dx=-dx;
    }


    if((abs(x_player1-x_ball)<=r_ball)&&y_ball>y_player1&&y_ball<y_player1+l_player1+20&&x_ball<x_player1)
    {
        x_ball-=10;
        dx=-dx;
    }



    if((abs(x_player2-x_ball)<=w_player2)&&y_ball>y_player2&&y_ball<y_player2+l_player2+20&&x_ball<x_player2)
    {
        x_ball-=10;
        dx=-dx;
    }


    if((abs(x_player2-x_ball)<=r_ball)&&y_ball>y_player2&&y_ball<y_player2+l_player2+20&&x_ball>x_player2)
    {
        x_ball+=10;
        dx=-dx;
    }


    if(x_ball<100&&y_ball>300)
    {
        isgoal = 1;
        Mix_PlayChannel(-1,crowd,0);
        if(!notgoal)
            player_1_goals++;
        powplus2*=2;
    }

    if(x_ball>1200&&y_ball>300)
    {
        isgoal2 = 1;
        Mix_PlayChannel(-1,crowd,0);
        player_2_goals++;
        powplus1*=2;
    }




    int x_head1 = x_player1  + 25, y_head1 = y_player1 - 39;

    int x_head2 = x_player2  + 25, y_head2 = y_player2 - 39;

    int x_head3 = x_player2c1  + 25, y_head3 = y_player2c1 - 39;

    int x_head4 = x_player2c2  + 25, y_head4 = y_player2c2 - 39;

    int x_BALL1 = x_ball + 25, y_BALL1 = y_ball + 25;



    if(trip)
        if(((x_head3-x_BALL1)*(x_head3-x_BALL1)+(y_head3-y_BALL1)*(y_head3-y_BALL1) <= (25 + 39)*(25 + 39)))
        {
            double dist = sqrt((x_head3-x_BALL1)*(x_head3-x_BALL1)+(y_head3-y_BALL1)*(y_head3-y_BALL1));

            double fOverlap = 0.5 * (dist - 25 - 39);

            double vecx = (x_BALL1 - x_head3)/dist;
            double vecy = (y_BALL1 - y_head3)/dist;


            double vcolx = -dx;
            double vcoly = vy_player2-dy;


            double speed = vcolx * vecx + vcoly * vecy;


//        cout<<"y";


            double impulse = 2 * speed / 11;
            dx += impulse * 10 * vecx;
            dy += impulse * 10 * vecy;
            //vx_player1 -= impulse * 1 * vecx;
            //vy_player1 -= impulse * 1 * vecx;

            x_ball += 2*(fOverlap * (x_head3 - x_BALL1) / dist);
            y_ball += 2*(fOverlap * (y_head3 - y_BALL1) / dist);


        }
    if(trip)
        if(((x_head4-x_BALL1)*(x_head4-x_BALL1)+(y_head4-y_BALL1)*(y_head4-y_BALL1) <= (25 + 39)*(25 + 39)))
        {
            double dist = sqrt((x_head4-x_BALL1)*(x_head4-x_BALL1)+(y_head4-y_BALL1)*(y_head4-y_BALL1));

            double fOverlap = 0.5 * (dist - 25 - 39);

            double vecx = (x_BALL1 - x_head4)/dist;
            double vecy = (y_BALL1 - y_head4)/dist;


            double vcolx = -dx;
            double vcoly = vy_player2-dy;


            double speed = vcolx * vecx + vcoly * vecy;


//        cout<<"y";


            double impulse = 2 * speed / 11;
            dx += impulse * 10 * vecx;
            dy += impulse * 10 * vecy;
            //vx_player1 -= impulse * 1 * vecx;
            //vy_player1 -= impulse * 1 * vecx;

            x_ball += 2*(fOverlap * (x_head4 - x_BALL1) / dist);
            y_ball += 2*(fOverlap * (y_head4 - y_BALL1) / dist);


        }




    if(((x_head1-x_BALL1)*(x_head1-x_BALL1)+(y_head1-y_BALL1)*(y_head1-y_BALL1) <= (25 + 39)*(25 + 39)))
    {
        double dist = sqrt((x_head1-x_BALL1)*(x_head1-x_BALL1)+(y_head1-y_BALL1)*(y_head1-y_BALL1));

        double fOverlap = 0.5 * (dist - 25 - 39);

        double vecx = (x_BALL1 - x_head1)/dist;
        double vecy = (y_BALL1 - y_head1)/dist;


        double vcolx = -dx;
        double vcoly = vy_player1-dy;


        double speed = vcolx * vecx + vcoly * vecy;


//        cout<<"y";


        double impulse = 2 * speed / 11;
        dx += impulse * 10 * vecx;
        dy += impulse * 10 * vecy;
        //vx_player1 -= impulse * 1 * vecx;
        //vy_player1 -= impulse * 1 * vecx;

        x_ball += 2*(fOverlap * (x_head1 - x_BALL1) / dist);
        y_ball += 2*(fOverlap * (y_head1 - y_BALL1) / dist);


    }


    if(((x_head2-x_BALL1)*(x_head2-x_BALL1)+(y_head2-y_BALL1)*(y_head2-y_BALL1) <= (25 + 39)*(25 + 39)))
    {
        double dist = sqrt((x_head2-x_BALL1)*(x_head2-x_BALL1)+(y_head2-y_BALL1)*(y_head2-y_BALL1));


        float fOverlap = 0.5 * (dist - 25 - 39);


        double vecx = (x_BALL1 - x_head2)/dist;
        double vecy = (y_BALL1 - y_head2)/dist;

        double vcolx = -dx;
        double vcoly = vy_player2-dy;


        double speed = vcolx * vecx + vcoly * vecy;



        double impulse = 2 * speed / 11;
        dx += impulse * 10 * vecx;
        dy += impulse * 10 * vecy;
        //vx_player2 -= impulse * 1 * vecx;
        //vy_player2 -= impulse * 1 * vecx;



        x_ball += 2*(fOverlap * (x_head2 - x_BALL1) / dist);
        y_ball += 2*(fOverlap * (y_head2 - y_BALL1) / dist);



    }

    if((abs(x_player1-x_player2)<=w_player1+24))
    {
        x_player1-=1;
        x_player2+=1;
    }

    if(fireball)
        fireball = 0;



}


void punch()
{
    power1L = 0;

    uint32_t ctime;
    ctime = SDL_GetTicks();

    elapsedTime = (ctime - punchtime) / 100;

//    cout<<punchdet<<endl;
    if(elapsedTime==30)
    {
        punchdet = 0;
        isran = 0;
    }

    def();



}
void inball()
{
    power1L = 0;
    uint32_t ctime;

    ctime = SDL_GetTicks();

    etime = (ctime - intime) / 1000;



    //cout<<indet<<endl;

    if(etime==2)
    {
        indet = 0;
        isran = 0;
    }

    def();
}
void fire()
{
    uint32_t cttime = SDL_GetTicks();

    double ettime = (cttime - firetime)/1000;

    //cout<<ettime<<endl;
    shoot();
    if(ettime >= 3)
        isfireball = 0;

    // fireball = 0;
    def();
}

void checkend()
{
    if(conditionn==2)
    {
        if(player_1_goals==5||player_2_goals==5)
            endgame = 1;

        else if(player_1_goals==4&&player_2_goals==4)
            endgame = 1;
    }
    else
    {
        if((SDL_GetTicks() - startTime)/1000==120)
            endgame = 1;
    }



}

void triple()
{
    uint32_t ttime = SDL_GetTicks();

    double timepas = (ttime - triptime)/1000;

    if(timepas==3)
    {
        trip=0;
        isran = 0;
    }


    def();



}

void menu()
{

    if(flag2==1)
    {
        //rasm menu1
        defm1();
        text1();
        SDL_RenderPresent(m_renderer);
    }
    while((flag==1)&&(flag2==1))
    {
        player1text();

    }
    while(flag3==1)
    {
        player2text();
    }
    if(flag9==0)
    {
        player1.erase(player1.begin(),player1.begin()+1);
        player2.erase(player2.begin(),player2.begin()+1);
    }
    flag9=1;
    bool found=false;

    for(int i=0; i<leaderboard.size(); i++)
    {
        if(leaderboard[i]==player1)
        {
            ph1=i+1;
            found=true;
            break;
        }
    }
    if(!found)
    {
        ph1=0;
    }

    bool found1=false;

    for(int i=0; i<leaderboard.size()-1; i++)
    {
        if(leaderboard[i]==player2)
        {
            ph2=i+1;
            found1=true;
            break;
        }
    }
    if(!found1)
    {
        ph2=0;
    }
    get_xy_mouse();
    e->type=NULL;
    //mouse movment
    check_mousemovement();

    SDL_RenderPresent(m_renderer);
    SDL_Delay(3);


}
void get_xy_mouse()
{
    Uint32 buttons;
    SDL_PumpEvents();
    buttons = SDL_GetMouseState(&mx, &my);
}
void text1()
{
    const char * text ="Enter name of teams:";
    int font =2;
    int x_position=450;
    int y_position=250;
    SDL_Color text_color = {250,250,250};
    textColor(m_renderer,x_position,y_position,text,font,40,text_color);

}
void text2()
{
    const char * text ="game information:";
    int font =2;
    int x_position=100;
    int y_position=50;
    SDL_Color text_color = {250,250,250};
    textColor(m_renderer,x_position,y_position,text,font,40,text_color);

}
void player1text()
{
    SDL_PollEvent(e);
    if(e->key.keysym.sym==SDLK_RETURN)
    {
        e->type=NULL;
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        SDL_RenderPresent(m_renderer);
        flag2=0;
    }
    if((e->key.keysym.sym==SDLK_BACKSPACE)&&(flag4==0))
    {
        player1.pop_back();
        defm1();
        text1();
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        SDL_RenderPresent(m_renderer);
        flag4=1;
    }
    else if(e->type==SDL_TEXTINPUT)
    {
        flag4=0;
        player1+=e->text.text;
    }
    SDL_StartTextInput();
    e->type=0;
    textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
    SDL_RenderPresent(m_renderer);
}
void player2text()
{
    SDL_PollEvent(p);
    if(p->key.keysym.sym==SDLK_RETURN&&player2!=" ")
    {
        p->type=0;
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,1000,250,player2.c_str(),2,30,255,255,255,255);
        SDL_RenderPresent(m_renderer);
        flag3 = 0;
    }
    if((p->key.keysym.sym==SDLK_BACKSPACE)&&(flag5==0))
    {
        player2.pop_back();
        defm1();
        text1();
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,1000,250,player2.c_str(),2,30,255,255,255,255);
        SDL_RenderPresent(m_renderer);
        flag5=1;
    }
    else if(p->type==SDL_TEXTINPUT)
    {
        flag5=0;
        player2+=p->text.text;
    }
    SDL_StartTextInput();
    p->type=0;
    textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
    textRGBA(m_renderer,1000,250,player2.c_str(),2,30,255,255,255,255);
    SDL_RenderPresent(m_renderer);
}
void ballmenu()
{
    SDL_Rect ball_back= {x_backm, y_backm,1180, 700};
    SDL_RenderCopy( m_renderer,ballback, NULL,&ball_back);
    rect(m_renderer,100,100,1080,600,255,255,255,100);
    SDL_Rect ball_1= {150,200,150, 150};
    SDL_RenderCopy( m_renderer,ball1, NULL,&ball_1);
    SDL_Rect ball_2= {400,200,170, 150};
    SDL_RenderCopy( m_renderer,ball2, NULL,&ball_2);
    SDL_Rect ball_3= {650,200,150, 150};
    SDL_RenderCopy( m_renderer,ball3, NULL,&ball_3);
    SDL_Rect ball_4= {900,200,150, 150};
    SDL_RenderCopy( m_renderer,ball4, NULL,&ball_4);
    SDL_Rect ball_5= {150,420,150, 150};
    SDL_RenderCopy( m_renderer,ball5, NULL,&ball_5);
    SDL_Rect ball_6= {400,420,170, 170};
    SDL_RenderCopy( m_renderer,ball6, NULL,&ball_6);
    SDL_Rect ball_7= {650,430,150, 150};
    SDL_RenderCopy( m_renderer,ball7, NULL,&ball_7);
    SDL_Rect ball_8= {900,430,150, 150};
    SDL_RenderCopy( m_renderer,ball8, NULL,&ball_8);
}
void ballmenu2()
{

    SDL_Rect ball_back= {x_backm, y_backm,1180, 700};
    SDL_RenderCopy( m_renderer,ballback, NULL,&ball_back);
    rect(m_renderer,100,100,1080,600,255,255,255,100);
    //back button:
    SDL_Rect back_b= {900,600,100,100};
    SDL_RenderCopy( m_renderer,backb, NULL,&back_b);
    //text:
    const char * text ="this ball is selected:";
    int font =2;
    int x_position=150;
    int y_position=200;
    SDL_Color text_color = {0,0,0};
    textColor(m_renderer,x_position,y_position,text,font,40,text_color);
    if((mx>=150)&&(mx<=300)&&(my>=200)&&(my<=350))
    {
        SDL_Rect ball_1= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball1, NULL,&ball_1);
        ballnumber=1;
    }
    else if((mx>=400)&&(mx<=570)&&(my>=200)&&(my<=350))
    {
        SDL_Rect ball_2= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball2, NULL,&ball_2);
        ballnumber=2;
    }
    else if((mx>=650)&&(mx<=800)&&(my>=200)&&(my<=350))
    {
        SDL_Rect ball_3= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball3, NULL,&ball_3);
        ballnumber=3;
    }
    else if((mx>=900)&&(mx<=1050)&&(my>=200)&&(my<=350))
    {
        SDL_Rect ball_4= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball4, NULL,&ball_4);
        ballnumber=4;
    }
    else if((mx>=150)&&(mx<=320)&&(my>=240)&&(my<=640))
    {
        SDL_Rect ball_5= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball5, NULL,&ball_5);
        ballnumber=5;
    }
    else if((mx>=400)&&(mx<=570)&&(my>=420)&&(my<=590))
    {
        SDL_Rect ball_6= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball6, NULL,&ball_6);
        ballnumber=6;
    }
    else if((mx>=650)&&(mx<=800)&&(my>=430)&&(my<=580))
    {
        SDL_Rect ball_7= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball7, NULL,&ball_7);
        ballnumber=7;
    }
    else if((mx>=900)&&(mx<=1050)&&(my>=430)&&(my<=580))
    {
        SDL_Rect ball_8= {400,400,300, 300};
        SDL_RenderCopy( m_renderer,ball8, NULL,&ball_8);
        ballnumber=8;
    }

}
void fieldmenu()
{
    SDL_Rect field_back= {x_backm,0,1200, 800};
    SDL_RenderCopy( m_renderer,fieldback, NULL,&field_back);
    rect(m_renderer,100,150,1080,500,255,255,255,100);
    SDL_Rect field_1= {150,200,150, 150};
    SDL_RenderCopy( m_renderer,field1, NULL,&field_1);
    SDL_Rect field_2= {400,200,150, 150};
    SDL_RenderCopy( m_renderer,field2, NULL,&field_2);
    SDL_Rect field_3= {650,200,150, 150};
    SDL_RenderCopy( m_renderer,field3, NULL,&field_3);
    SDL_Rect field_4= {900,200,150, 150};
    SDL_RenderCopy( m_renderer,field4, NULL,&field_4);
    SDL_Rect field_5= {150,400,150, 150};
    SDL_RenderCopy( m_renderer,field5, NULL,&field_5);

}
void fieldmenu2()
{

    SDL_Rect field_back= {x_backm, y_backm,1180, 700};
    SDL_RenderCopy( m_renderer,fieldback, NULL,&field_back);
    rect(m_renderer,100,100,1080,600,255,255,255,100);
    //back button:
    SDL_Rect back_b= {900,600,100,100};
    SDL_RenderCopy( m_renderer,backb, NULL,&back_b);
    //text:
    const char * text ="this field is selected:";
    int font =2;
    int x_position=150;
    int y_position=200;
    SDL_Color text_color = {0,0,0};
    textColor(m_renderer,x_position,y_position,text,font,40,text_color);
    if((mx>=150)&&(mx<=300)&&(my>=200)&&(my<=350))
    {
        SDL_Rect field_1= {400,400,200,200};
        SDL_RenderCopy( m_renderer,field1, NULL,&field_1);
        fieldnumber=1;
    }
    else if((mx>=400)&&(mx<=570)&&(my>=200)&&(my<=350))
    {
        SDL_Rect field_2= {400,400,200, 200};
        SDL_RenderCopy( m_renderer,field2, NULL,&field_2);
        fieldnumber=2;
    }
    else if((mx>=650)&&(mx<=800)&&(my>=200)&&(my<=350))
    {
        SDL_Rect field_3= {400,400,200, 200};
        SDL_RenderCopy( m_renderer,field3, NULL,&field_3);
        fieldnumber=3;
    }
    else if((mx>=900)&&(mx<=1050)&&(my>=200)&&(my<=350))
    {
        SDL_Rect field_4= {400,400,200,200};
        SDL_RenderCopy( m_renderer,field4, NULL,&field_4);
        fieldnumber=4;
    }
    else if((mx>=150)&&(mx<=320)&&(my>=240)&&(my<=640))
    {
        SDL_Rect field_5= {400,400,200,200};
        SDL_RenderCopy( m_renderer,field5, NULL,&field_5);
        fieldnumber=5;
    }


}
void leaguemenu()
{

    SDL_Rect playerback_3= {50,0,1200, 200};
    SDL_RenderCopy( m_renderer,playerback3, NULL,&playerback_3);

    SDL_Rect table_0= {200,200,900, 600};
    SDL_RenderCopy( m_renderer,table, NULL,&table_0);

    const char * text ="team name";
    SDL_Color text_color = {250,250,250};
    textColor(m_renderer,230,290,text,2,26,text_color);

    const char * text1 ="team score";
    textColor(m_renderer,940,290,text1,2,26,text_color);

    SDL_Rect back_b= {1100,700,100,100};
    SDL_RenderCopy( m_renderer,backb, NULL,&back_b);


    for(int i=0; i<leaderboard.size()-1; i+=2)
    {
        textRGBA(m_renderer,260,370+20*i,leaderboard[i].c_str(),2,20,255,255,255,255);
        textRGBA(m_renderer,950,370+20*i,leaderboard[i+1].c_str(),2,20,255,255,255,255);
    }

    SDL_RenderPresent(m_renderer);

}
void historymenu()
{
    SDL_Rect playerback_2= {x_backm,0,1200, 800};
    SDL_RenderCopy( m_renderer,playerback2, NULL,&playerback_2);
    SDL_Rect history_1= {200,100,900,500};
    SDL_RenderCopy( m_renderer,table, NULL,&history_1);
    textRGBA(m_renderer,250,330,player1.c_str(),2,40,255,255,255,255);
    textRGBA(m_renderer,250,390,player2.c_str(),2,40,255,255,255,255);

    const char * text ="team name";
    SDL_Color text_color = {250,250,250};
    textColor(m_renderer,230,290,text,2,26,text_color);

    const char * text1 ="team score";
    textColor(m_renderer,940,290,text1,2,26,text_color);

    if(ph1==0)
    {
        const char * ps1 ="0";
        textRGBA(m_renderer,960,330,ps1,2,26,255,255,255,255);
    }
    else
    {
        textRGBA(m_renderer,960,330,leaderboard[ph1].c_str(),2,30,255,255,255,255);
    }
    if(ph2==0)
    {
        const char * ps2 ="0";
        textRGBA(m_renderer,960,390,ps2,2,26,255,255,255,255);
    }
    else
    {
        textRGBA(m_renderer,960,390,leaderboard[ph2].c_str(),2,30,255,255,255,255);
    }
    //back button:
    SDL_Rect back_b= {900,600,100,100};
    SDL_RenderCopy( m_renderer,backb, NULL,&back_b);
    SDL_RenderPresent(m_renderer);
}

void playermenu()
{
    SDL_Rect playerback_4= {x_backm,0,1200, 800};
    SDL_RenderCopy( m_renderer,playerback4, NULL,&playerback_4);
    textRGBA(m_renderer,500,150,player1.c_str(),2,30,0,0,0,255);
    textRGBA(m_renderer,750,150,player2.c_str(),2,30,0,0,0,255);
    //back button:
    SDL_Rect back_b= {900,600,100,100};
    SDL_RenderCopy(m_renderer,backb, NULL,&back_b);

    rect(m_renderer,500,300,70,150,r1,g1,b1,255);
    rect(m_renderer,750,300,70,150,r2,g2,b2,255);

    filledEllipseRGBA(m_renderer,785,300,50,50,rc2,gc2,bc2,255);
    filledEllipseRGBA(m_renderer,535,300,50,50,rc1,gc1,bc1,255);
    SDL_Rect half0 = {500,450,70,50};
    SDL_Rect half1 = {750,450,70,50};
    SDL_Rect shoe0 = {535,495, 50, 20};
    SDL_Rect shoe1 = {515,495, 50, 20};
    SDL_Rect shoe02 = {745,495, 50, 20};
    SDL_Rect shoe3= {765,495, 50, 20};
    SDL_Rect perple0= {xp,yp,70,70};
    SDL_Rect blue0= {xp,yp+90,70,70};
    SDL_Rect red0= {xp,yp+180,70,70};
    SDL_Rect yellow0= {xp,yp+270,70,70};
    SDL_Rect green0= {xp,yp+360,70,70};

    SDL_Rect perple1= {xp2+90,yp,70,70};
    SDL_Rect blue1= {xp2+90,yp+90,70,70};
    SDL_Rect red1= {xp2+90,yp+180,70,70};
    SDL_Rect yellow1= {xp2+90,yp+270,70,70};
    SDL_Rect green1= {xp2+90,yp+360,70,70};

    SDL_Rect perplec0= {xp2,yp,70,70};
    SDL_Rect bluec0= {xp2,yp+80,70,70};
    SDL_Rect redc0= {xp2,yp+160,70,70};
    SDL_Rect yellowc0= {xp2,yp+240,70,70};
    SDL_Rect greenc0= {xp2,yp+320,70,70};

    SDL_Rect perplec1= {xp+90,yp,70,70};
    SDL_Rect bluec1= {xp+90,yp+80,70,70};
    SDL_Rect redc1= {xp+90,yp+160,70,70};
    SDL_Rect yellowc1= {xp+90,yp+240,70,70};
    SDL_Rect greenc1= {xp+90,yp+320,70,70};


    SDL_RenderCopy(m_renderer,halfm,NULL,&half1);
    SDL_RenderCopy(m_renderer,halfm, NULL,&half0);
    SDL_RenderCopy(m_renderer,shoem,NULL,&shoe3);
    SDL_RenderCopy(m_renderer,shoem, NULL,&shoe02);
    SDL_RenderCopy(m_renderer,shoe2m, NULL,&shoe1);
    SDL_RenderCopy(m_renderer,shoe2m, NULL,&shoe0);
    SDL_RenderCopy(m_renderer,perple, NULL,&perple0);
    SDL_RenderCopy(m_renderer,perplec, NULL,&perplec0);
    SDL_RenderCopy(m_renderer,red, NULL,&red0);
    SDL_RenderCopy(m_renderer,redc, NULL,&redc0);
    SDL_RenderCopy(m_renderer,yellow, NULL,&yellow0);
    SDL_RenderCopy(m_renderer,yellowc, NULL,&yellowc0);
    SDL_RenderCopy(m_renderer,blue, NULL,&blue0);
    SDL_RenderCopy(m_renderer,bluec, NULL,&bluec0);
    SDL_RenderCopy(m_renderer,green, NULL,&green0);
    SDL_RenderCopy(m_renderer,greenc, NULL,&greenc0);

    SDL_RenderCopy(m_renderer,perple, NULL,&perple1);
    SDL_RenderCopy(m_renderer,perplec, NULL,&perplec1);
    SDL_RenderCopy(m_renderer,red, NULL,&red1);
    SDL_RenderCopy(m_renderer,redc, NULL,&redc1);
    SDL_RenderCopy(m_renderer,yellow, NULL,&yellow1);
    SDL_RenderCopy(m_renderer,yellowc, NULL,&yellowc1);
    SDL_RenderCopy(m_renderer,blue, NULL,&blue1);
    SDL_RenderCopy(m_renderer,bluec, NULL,&bluec1);
    SDL_RenderCopy(m_renderer,green, NULL,&green1);
    SDL_RenderCopy(m_renderer,greenc, NULL,&greenc1);

}
void checkclick()
{
    if((x>=xp)&&(x<=xp+70)&&(y>=yp)&&(y<=yp+70))
    {
        //1t perple
        r1=128,b1=128,g1=0;
    }
    else if((x>=xp)&&(x<=xp+70)&&(y>=yp+90)&&(y<=yp+70+90))
    {
        //1t blue
        r1=0,b1=255,g1=0;
    }
    else if((x>=xp)&&(x<=xp+70)&&(y>=yp+180)&&(y<=yp+70+180))
    {
        //1t red
        r1=255,b1=0,g1=0;
    }
    else if((x>=xp)&&(x<=xp+70)&&(y>=yp+270)&&(y<=yp+70+270))
    {
        //1t yellow
        r1=255,b1=0,g1=255;
    }
    else if((x>=xp)&&(x<=xp+70)&&(y>=yp+360)&&(y<=yp+70+360))
    {
        //1t green
        r1=0,b1=0,g1=128;
    }
    if((x>=xp2+90)&&(x<=xp2+90+70)&&(y>=yp)&&(y<=yp+70))
    {
        //2t perple
        r2=128,b2=128,g2=0;
    }
    else if((x>=xp2+90)&&(x<=xp2+90+70)&&(y>=yp+90)&&(y<=yp+70+90))
    {
        //2t blue
        r2=0,b2=255,g2=0;
    }
    else if((x>=xp2+90)&&(x<=xp2+90+70)&&(y>=yp+180)&&(y<=yp+70+180))
    {
        //2t red
        r2=255,b2=0,g2=0;
    }
    else if((x>=xp2+90)&&(x<=xp2+90+70)&&(y>=yp+270)&&(y<=yp+70+270))
    {
        //2t yellow
        r2=255,b2=0,g2=255;
    }
    else if((x>=xp2+90)&&(x<=xp2+90+70)&&(y>=yp+360)&&(y<=yp+70+360))
    {
        //2t green
        r2=0,b2=0,g2=128;
    }
    else if((x>=xp2)&&(x<=xp2+70)&&(y>=yp)&&(y<=yp+70))
    {
        //2c perple
        rc2=128,bc2=128,gc2=0;
    }
    else if((x>=xp2)&&(x<=xp2+70)&&(y>=yp+90)&&(y<=yp+70+90))
    {
        //2c blue
        rc2=0,bc2=255,gc2=0;
    }
    else if((x>=xp2)&&(x<=xp2+70)&&(y>=yp+180)&&(y<=yp+70+180))
    {
        //2c red
        rc2=255,bc2=0,gc2=0;
    }
    else if((x>=xp2)&&(x<=xp2+70)&&(y>=yp+270)&&(y<=yp+70+270))
    {
        //2c yellow
        rc2=255,bc2=0,gc2=255;
    }
    else if((x>=xp2)&&(x<=xp2+70)&&(y>=yp+360)&&(y<=yp+70+360))
    {
        //2c green
        rc2=0,bc2=0,gc2=128;
    }
    else if((x>=xp+90)&&(x<=xp+90+70)&&(y>=yp)&&(y<=yp+70))
    {
        //1c perple
        rc1=128,bc1=128,gc1=0;
    }
    else if((x>=xp+90)&&(x<=xp+90+70)&&(y>=yp+90)&&(y<=yp+70+90))
    {
        //1c blue
        rc1=0,bc1=255,gc1=0;
    }
    else if((x>=xp+90)&&(x<=xp+90+70)&&(y>=yp+180)&&(y<=yp+70+180))
    {
        //1c red
        rc1=255,bc1=0,gc1=0;
    }
    else if((x>=xp+90)&&(x<=xp+90+70)&&(y>=yp+270)&&(y<=yp+70+270))
    {
        //1c yellow
        rc1=255,bc1=0,gc1=255;
    }
    else if((x>=xp+90)&&(x<=xp+90+70)&&(y>=yp+360)&&(y<=yp+70+360))
    {
        //1c green
        rc1=0,bc1=0,gc1=128;
    }
    else if((x>=900)&&(x<=1000)&&(y>=600)&&(y<=700))
    {
        flag8=0;
    }
}
void check_mousemovement()
{
    click=Mix_LoadWAV("click.wav");
    if((mx>=x_play+80)&&(mx<=x_play+150)&&(my>=y_play+110)&&(my<=y_play+180))
    {
        e->type=0;
        SDL_PollEvent(e);
        if(e->type==SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1,click,0);
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                flag2=0;
                while(flag2==0)
                {
                    SDL_RenderClear(m_renderer);
                    window_color(m_renderer,255,255,255);
                    SDL_Rect back_m1= {x_backm,y_backm,1080,800};
                    SDL_RenderCopy(m_renderer,note,NULL,&back_m1);
                    const char * text111 ="Rules of the game:";
                    const char * text112 =">>Use the (W)(A)(D) keys to move the player 1 and the (X) key to shoot";
                    const char * text113 =">>Use the (I)(J)(L) keys to move player 2 and the (U) key to shoot";
                    const char * text114 =">>The game ends in two ways, which are:";
                    const char * text115 ="1-time limit (2 minutes)";
                    const char * text116 ="2-goal limit (5 goals)";
                    const char * text117 ="These items can be selected from the home icon section";
                    const char * text118=">>Players have special powers that are specific to them as follows:";
                    const char * text119 ="q-->punch player1";
                    const char * text120="p-->fireball player1";
                    const char * text121 ="v-->tripleclone player2";
                    const char * text122 ="m-->thief player2";
                    const char * text123 ="z-->invisible ball player2";

                    int font =2;
                    int x_position=150;
                    int y_position=250;
                    SDL_Color text_color = {0,0,0};

                    textColor(m_renderer,x_position+300,y_position-70,text111,font,40,text_color);
                    textColor(m_renderer,x_position,y_position+30,text112,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+60,text113,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+90,text114,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+120,text115,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+150,text116,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+180,text117,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+210,text118,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+240,text119,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+270,text120,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+300,text121,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+330,text122,font,20,text_color);
                    textColor(m_renderer,x_position,y_position+360,text123,font,20,text_color);

                    SDL_Rect back_b= {900,600,100,100};
                    SDL_RenderCopy( m_renderer,backb, NULL,&back_b);

                    SDL_RenderPresent(m_renderer);

                    flag6=0;
                    while(flag6==0)
                    {
                        Uint32 buttons;
                        SDL_PumpEvents();
                        buttons = SDL_GetMouseState(&nx, &ny);
                        e->type=0;
                        SDL_PollEvent(e);
                        if(e->type==SDL_MOUSEBUTTONDOWN)
                        {
                            Mix_PlayChannel(-1,click,0);
                            if(e->button.button==SDL_BUTTON_LEFT)
                            {
                                if((nx>=900)&&(nx<=1000)&&(ny>=600)&&(ny<=700))
                                {
                                    flag2=2;
                                    e->type=0;
                                    defm1();
                                    textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
                                    textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
                                    SDL_RenderPresent(m_renderer);
                                    break;
                                }

                                e->type=0;
                            }
                        }
                    }
                    flag6=1;
                }

            }
        }
    }

//player icon:
else if((mx>=90)&&(mx<=180)&&(my>=670)&&(my<=760))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,255,255,255);
                playermenu();
                SDL_RenderPresent(m_renderer);
                flag8=1;
                while(flag8==1)
                {

                    Uint32 buttons;
                    SDL_PumpEvents();
                    buttons = SDL_GetMouseState(&x, &y);
                    e->type=0;
                    SDL_PollEvent(e);
                    if(e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        Mix_PlayChannel(-1,click,0);
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {
                            SDL_RenderClear(m_renderer);
                            window_color(m_renderer,255,255,255);
                            checkclick();
                            playermenu();
                            SDL_RenderPresent(m_renderer);
                        }
                    }
                }

                defm1();
                textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
                textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
                SDL_RenderPresent(m_renderer);
                break;
            }
        }
    }
}
//history icon:
else if((mx>=1100)&&(mx<=1200)&&(my>=680)&&(my<=750))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,255,255,255);
                historymenu();
                SDL_RenderPresent(m_renderer);
                flag6=0;
                while(flag6==0)
                {
                    Uint32 buttons;
                    SDL_PumpEvents();
                    buttons = SDL_GetMouseState(&nx, &ny);
                    e->type=0;
                    SDL_PollEvent(e);
                    if(e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        Mix_PlayChannel(-1,click,0);
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {
                            if((nx>=900)&&(nx<=1000)&&(ny>=600)&&(ny<=700))
                            {
                                flag2=2;
                                e->type=0;
                                defm1();
                                textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
                                textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
                                SDL_RenderPresent(m_renderer);
                                break;
                            }

                            e->type=0;
                        }
                    }
                }
                flag6=1;
            }
        }
    }
}

//play icon:
if((mx>=550)&&(mx<=750)&&(my>=599)&&(my<=699))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            menurun = 0;

        }
    }
}
//league icon:
else if((mx>=100)&&(mx<=170)&&(my>=599)&&(my<=669))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,255,255,255);
                leaguemenu();
                SDL_RenderPresent(m_renderer);
                flag2=1;
                flag6=0;
                while(flag6==0)
                {
                    e->type=NULL;
                    SDL_PollEvent(e);
                    Uint32 buttons;
                    SDL_PumpEvents();
                    buttons = SDL_GetMouseState(&nx, &ny);

                    if(e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        Mix_PlayChannel(-1,click,0);
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {

                            if((nx>=1100)&&(nx<=1200)&&(ny>=700)&&(ny<=800))
                            {
                                flag2=2;
                                e->type=0;
                                defm1();
                                textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
                                textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
                                SDL_RenderPresent(m_renderer);
                                break;
                            }

                            e->type=0;
                        }
                    }
                }
                flag6=1;
            }
            flag2=5;
        }
    }
}
//ballm icon:
else if((mx>=100)&&(mx<=170)&&(my>=500)&&(my<=570))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,0,0,0);
                ballmenu();
                SDL_RenderPresent(m_renderer);

                get_xy_mouse();
                e->type=0;
                SDL_PollEvent(e);
                if(e->type==SDL_MOUSEBUTTONDOWN)
                {
                    if(e->button.button==SDL_BUTTON_LEFT)
                    {
                        SDL_RenderClear(m_renderer);
                        window_color(m_renderer,0,0,0);
                        flag2=0;
                        while(flag2==0)
                        {
                            ballmenu2();
                            SDL_RenderPresent(m_renderer);
                            flag6=0;
                            while(flag6==0)
                            {
                                Uint32 buttons;
                                SDL_PumpEvents();
                                buttons = SDL_GetMouseState(&nx, &ny);

                                e->type=0;
                                SDL_PollEvent(e);
                                if(e->type==SDL_MOUSEBUTTONDOWN)
                                {
                                    Mix_PlayChannel(-1,click,0);
                                    if(e->button.button==SDL_BUTTON_LEFT)
                                    {

                                        if((nx>=900)&&(nx<=1000)&&(ny>=600)&&(ny<=700))
                                        {
                                            flag2=2;
                                            e->type=0;
                                            defm1();
                                            break;
                                        }

                                        e->type=0;
                                    }
                                }
                            }
                            flag6=1;
                        }

                    }

                }
            }
        }
    }
    SDL_RenderPresent(m_renderer);
    SDL_Delay(10);
}
//ground icon:
else if((mx>=1110)&&(mx<=1180)&&(my>=599)&&(my<=669))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,255,255,255);
                fieldmenu();
                SDL_RenderPresent(m_renderer);

                get_xy_mouse();
                e->type=0;
                SDL_PollEvent(e);
                if(e->type==SDL_MOUSEBUTTONDOWN)
                {
                    Mix_PlayChannel(-1,click,0);
                    if(e->button.button==SDL_BUTTON_LEFT)
                    {
                        SDL_RenderClear(m_renderer);
                        window_color(m_renderer,255,255,255);
                        flag2=0;
                        while(flag2==0)
                        {
                            fieldmenu2();
                            SDL_RenderPresent(m_renderer);
                            int flag6=0;
                            while(flag6==0)
                            {
                                Uint32 buttons;
                                SDL_PumpEvents();
                                buttons = SDL_GetMouseState(&nx, &ny);

                                e->type=0;
                                SDL_PollEvent(e);
                                if(e->type==SDL_MOUSEBUTTONDOWN)
                                {
                                    Mix_PlayChannel(-1,click,0);
                                    if(e->button.button==SDL_BUTTON_LEFT)
                                    {

                                        if((nx>=900)&&(nx<=1000)&&(ny>=600)&&(ny<=700))
                                        {
                                            flag2=2;
                                            e->type=0;
                                            defm1();

                                            break;
                                        }

                                        e->type=0;
                                    }
                                }
                            }
                            flag6=1;
                        }

                    }

                }
            }
        }
    }
    SDL_RenderPresent(m_renderer);
    SDL_Delay(3);
}

//home icon:
else if((mx>=1110)&&(mx<=1180)&&(my>=500)&&(my<=570))
{
    e->type=0;
    SDL_PollEvent(e);
    if(e->type==SDL_MOUSEBUTTONDOWN)
    {
        Mix_PlayChannel(-1,click,0);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            flag2=0;
            while(flag2==0)
            {
                SDL_RenderClear(m_renderer);
                window_color(m_renderer,0,0,0);
                SDL_RenderCopy(m_renderer,settingb,NULL,NULL);
                //back button:
                SDL_Rect back_b= {900,600,100,100};
                SDL_RenderCopy( m_renderer,backb, NULL,&back_b);
                rect(m_renderer,800,260,330,80,105,200,200,255);
                const char * text ="Conditons of the game:";
                SDL_Color text_color = {0,0,0};
                textColor(m_renderer,830,290,text,2,26,text_color);

                rect(m_renderer,800,360,330,80,105,200,200,255);
                textColor(m_renderer,830,390,text11,2,26,text_color);

                rect(m_renderer,800,460,330,80,105,200,200,255);
                textColor(m_renderer,830,490,text22,2,26,text_color);

                rect(m_renderer,400,260,300,80,255,255,255,255);
                const char * text3 ="music of the game:";
                textColor(m_renderer,430,290,text3,2,26,text_color);
                SDL_Rect music1_0= {500,360,80,80};
                SDL_Rect music2_0= {500,460,80,80};

                SDL_RenderCopy(m_renderer,music1,NULL,&music1_0);
                SDL_RenderCopy(m_renderer,music2,NULL,&music2_0);


                SDL_RenderPresent(m_renderer);
                int flag6=0;
                while(flag6==0)
                {
                    Uint32 buttons;
                    SDL_PumpEvents();
                    buttons = SDL_GetMouseState(&nx, &ny);

                    e->type=0;
                    SDL_PollEvent(e);
                    if(e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        Mix_PlayChannel(-1,click,0);
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {

                            if((nx>=800)&&(nx<=1130)&&(ny>=360)&&(ny<=440))
                            {
                                conditionn=1;
                            }
                            else if((nx>=800)&&(nx<=1130)&&(ny>=460)&&(ny<=540))
                            {
                                conditionn=2;
                            }
                            else if((nx>=500)&&(nx<=580)&&(ny>=360)&&(ny<=440))
                            {
                                music=1;
                            }
                            else if((nx>=500)&&(nx<=580)&&(ny>=460)&&(ny<=540))
                            {
                                music=2;
                            }
                            else if((nx>=900)&&(nx<=1000)&&(ny>=600)&&(ny<=700))
                            {
                                flag2=2;
                                e->type=0;
                                defm1();
                                textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
                                textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
                                SDL_RenderPresent(m_renderer);
                                break;
                            }

                            e->type=0;
                        }
                    }
                }
                flag6=1;
            }
        }
    }
}
}
void defm1()
{
    window_color(m_renderer,0,0,0);
    SDL_Rect back_m= {x_backm, y_backm,1180,700};
    SDL_Rect play_0= {x_play, y_play,200, 100};
    SDL_Rect league_0= {x_league, y_league, 70, 70};
    SDL_Rect ball_m= {x_ballm, y_ballm,70, 70};
    SDL_Rect ground_0= {x_ground, y_ground, 70, 70};
    SDL_Rect home_0= {x_home, y_home, 70, 70};
    SDL_Rect history_0= {1100,680,100,70};
    SDL_Rect player_0= {90,670,90,90};
    SDL_Rect note_0= {x_play+80,y_play+110,70,70};

    SDL_RenderCopy( m_renderer,backm, NULL,&back_m);
    SDL_RenderCopy( m_renderer,player, NULL,&player_0);
    SDL_RenderCopy( m_renderer,note_icon, NULL,&note_0);
    SDL_RenderCopy( m_renderer,play1, NULL, &play_0);
    SDL_RenderCopy( m_renderer,league, NULL, &league_0);
    SDL_RenderCopy( m_renderer,ballm, NULL, &ball_m);
    SDL_RenderCopy( m_renderer,ground, NULL, &ground_0);
    SDL_RenderCopy( m_renderer,home, NULL, &home_0);
    SDL_RenderCopy( m_renderer,history, NULL, &history_0);
    if(ballnumber!=0)
    {
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
        text2();
        string str1= to_string(ballnumber);
        string ballnumber="ball number:";
        textRGBA(m_renderer,100,100,ballnumber.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,270,100,str1.c_str(),2,30,255,255,255,255);
    }
    if(fieldnumber!=0)
    {
        textRGBA(m_renderer,200,250,player1.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,950,250,player2.c_str(),2,30,255,255,255,255);
        text2();
        string str= to_string(fieldnumber);
        string fieldnumber="field number:";
        textRGBA(m_renderer,100,130,fieldnumber.c_str(),2,30,255,255,255,255);
        textRGBA(m_renderer,280,130,str.c_str(),2,30,255,255,255,255);
    }
    if(conditionn!=0)
    {
        string str1= to_string(conditionn);
        string conditionofthegame="condition of the game:";
        SDL_Color text_color = {255,255,255};
        textRGBA(m_renderer,100,160,conditionofthegame.c_str(),2,30,255,255,255,255);
        if(conditionn==1)
        {
            textColor(m_renderer,400,160,text11,2,26,text_color);
        }
        else if(conditionn==2)
        {
            textColor(m_renderer,400,160,text22,2,26,text_color);
        }

    }
    if(music!=0)
    {
        string str1= to_string(music);
        string musicofthegame="music of the game:";
        SDL_Color text_color = {255,255,255};
        textRGBA(m_renderer,100,190,musicofthegame.c_str(),2,30,255,255,255,255);
        if(music==1)
        {
            textColor(m_renderer,390,190,str1.c_str(),2,26,text_color);
        }
        else if(music==2)
        {
            textColor(m_renderer,390,190,str1.c_str(),2,26,text_color);
        }

    }
    SDL_RenderPresent(m_renderer);
}

