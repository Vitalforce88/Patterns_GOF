
#include <conio.h>
#include <chrono>
#include <thread>
#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    MyTools::ProxyLog logger{ MyTools::LogSingleton::getInstance() };
    logger.OpenLogFile("log.txt");

    SBomber game{logger};

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(500ms);

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    MyTools::LogSingleton::getInstance().CloseLogFile();

    return 0;
}
