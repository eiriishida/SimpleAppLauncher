//Name
//Configurable Minimal Application Launcher

//Author
//Eiri Ishida 2021/09/28

//License
//CC BY-SA 4.0
//https://creativecommons.org/licenses/by-sa/4.0/deed.ja

//References
// https://wa3.i-3-i.info/index.html
// https://ja.stackoverflow.com/questions/61092/getprivateprofilestring%e9%96%a2%e6%95%b0%e3%81%a7%e3%82%a8%e3%83%a9%e3%83%bc
// https://www.ipentec.com/document/csharp-read-ini-file-value
// https://qiita.com/hirocueki/items/f5288b9fc757b10addb6
// https://qiita.com/takahiro_itazuri/items/e999ae24ab34b2756b04
// https://ja.cppreference.com/w/cpp/io/basic_ifstream/is_open
// http://kaitei.net/winapi/getting-started/
// https://blog.goo.ne.jp/masaki_goo_2006/e/bf6845919dd9a37f7a6df96bec01ab44
// https://marycore.jp/prog/cpp/concat-append-string/
// https://stackoverflow.com/questions/3906515/cannot-convert-from-stdstring-to-lpstr
// https://www.delftstack.com/ja/howto/cpp/how-to-wait-for-user-input-in-cpp/
// http://www.getnext.net/wp/?p=1148
// https://marycore.jp/prog/cpp/convert-char-to-string/
// https://www.sejuku.net/blog/52403
// https://www.delftstack.com/ja/howto/cpp/how-to-convert-char-array-to-string-in-cpp/
// http://stlalv.la.coocan.jp/Stream.html

//from stdc++
#include<string>
#include<fstream>
#include<iostream>

//from Microsoft
#include <tchar.h>
#include <windows.h>

//defining of a configuration file
char INIFILEPATH[] = ".\\applauncher_jupyter_updater.ini";

// a function checking whether a file exists or not
// This function is based on the code (licensed under CC BY-SA) in the webpage below;
// https://en.cppreference.com/w/cpp/io/basic_ifstream/is_open 
bool file_exists(const std::string& str)
{
   std::ifstream fs(str);
   return fs.is_open();
}

// main program
int WINAPI _tWinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    //making a configuration file if not exists
    if (!(file_exists(INIFILEPATH)))
    {
        std::ofstream(std::string(INIFILEPATH));
    }
    //setting up variables
    _TCHAR buffer01[256],buffer02[256],buffer03[256];
    GetPrivateProfileString("SETTINGS", "PYTHON3VARIABLES", "LANG=C",
        buffer01, sizeof(buffer01), INIFILEPATH);
    GetPrivateProfileString("SETTINGS", "PYTHON3PATH", "python3",
        buffer02, sizeof(buffer02), INIFILEPATH);
    GetPrivateProfileString("SETTINGS", "PYTHON3ARGUMENTS", "--version",
        buffer03, sizeof(buffer03), INIFILEPATH);
    std::string buffer04 = buffer02;
    buffer04 += " ";
    buffer04 += buffer03;
    LPSTR buffer05 = strdup(buffer04.c_str());
    //launching an app
    _putenv(buffer01);
    WinExec(buffer05, SW_SHOWNORMAL);
    std::cout << "Press Enter for Exitting";
    getchar();
    return 0;
}
