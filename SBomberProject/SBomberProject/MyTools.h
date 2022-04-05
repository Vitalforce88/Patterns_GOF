#pragma once

#include <stdint.h>
#include <string>
#include <fstream>

namespace MyTools {

    // ѕалитра цветов от 0 до 15
    enum  ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };

	//=============================================================================================

	void ClrScr();

	void __fastcall GotoXY(double x, double y);

	uint16_t GetMaxX();

	uint16_t GetMaxY();

    void SetColor(ConsoleColor color);

	//=============================================================================================
    // —инглтон(ќдиночка) Singleton(√арантирует что у класса есть только один экземпл€р и предоставл€ет к нему глобальную точку доступа)

    class InterLog {
    public:

       virtual ~InterLog() = default;

       virtual void __fastcall OpenLogFile(const std::string& FN) = 0;

       virtual void CloseLogFile() = 0;

       virtual void __fastcall WriteToLog(const std::string& str) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;

        
    };


    class LogSingleton : public InterLog{
    public:
        static LogSingleton& getInstance() {
            static LogSingleton theInstance;
            return theInstance;
        }

        void __fastcall OpenLogFile(const std::string& FN) override;
        void CloseLogFile() override;
        void __fastcall WriteToLog(const std::string& str) override;
        void __fastcall WriteToLog(const std::string& str, int n) override;
        void __fastcall WriteToLog(const std::string& str, double d) override;

    private:
        
        
        LogSingleton(){};
        LogSingleton(const LogSingleton& root) = delete;
        LogSingleton& operator = (const LogSingleton&) = delete;
        LogSingleton(const LogSingleton&& root) = delete;
        LogSingleton& operator = (const LogSingleton&&) = delete;

        static std::string GetCurDateTime(); 
        std :: ofstream logOut;     
    };
	
    
	//=============================================================================================
    //Proxy(заместитель) - контролирует доступ к объекту
    class ProxyLog : public InterLog {
    public:
        ProxyLog(InterLog& log) : logger{ log }{}
        ~ProxyLog() override;
        void __fastcall OpenLogFile(const std::string& FN) override;
        void CloseLogFile() override;
        void __fastcall WriteToLog(const std::string& str) override;
        void __fastcall WriteToLog(const std::string& str, int n) override;
        void __fastcall WriteToLog(const std::string& str, double d) override;

    private:
        InterLog& logger;
        uint32_t counter{ 0u };
    };

};