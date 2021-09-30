//本プログラムは以下のサイト・ページを参考に作成しました。
// https://blog.goo.ne.jp/masaki_goo_2006/e/bf6845919dd9a37f7a6df96bec01ab44
// http://eternalwindows.jp/winbase/window/window03.html
// http://timgolden.me.uk/pywin32-docs/
// https://docs.microsoft.com/ja-jp/windows/win32/learnwin32/winmain--the-application-entry-point
// https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/reference/putenv-wputenv
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winexec
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow
// http://www.interface.co.jp/catalog/prdchelp/japanese/gpc2910c/Example.htm
// http://wisdom.sakura.ne.jp/system/winapi/win32/win3.html
// https://www.tokovalue.jp/function/ShowWindow.htm
// https://cat-in-136.github.io/2012/04/unicodemingw32twinmainwwinmain.html
// http://chokuto.ifdef.jp/urawaza/api/ShowWindow.html

#include <tchar.h>
#include <Windows.h>

extern int WINAPI _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
    // IDLE
    _putenv("LANG=ja_JP.UTF-8");
    WinExec( "D:\\WPy64-3870\\python-3.8.7.amd64\\pythonw.exe D:\\WPy64-3870\\python-3.8.7.amd64\\Lib\\idlelib\\idle.pyw", SW_SHOWNORMAL );
    return 0;
}
