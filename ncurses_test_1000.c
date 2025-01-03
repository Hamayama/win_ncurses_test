
// ncurses テストプログラム
// 2025-1-3 v1.00

// ncurses のワイド文字対応設定
// (これを記述しないと mvaddwstr 等が使えない)
#define NCURSES_WIDECHAR 1

#include <ncurses/ncurses.h>
#include <locale.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <windows.h>

int main(void)
{
    // 初期化
    setlocale(LC_ALL, "");  // ロケール設定(なくても良い?)
    initscr();              // 画面初期化
    noecho();               // 入力された文字を表示しない
    curs_set(0);            // カーソル非表示

    // 画面サイズ設定
    // (幅を 1 文字分狭くしないと、日本語の表示がずれる)
    resize_term(LINES, COLS - 1);

    // 画面クリア
    clear();

    // 文字表示
    mvaddwstr(0, 0,  L"あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやいゆえよ");
    mvaddwstr(1, 0,  L"１２３４５６７８９０１２３４５６７８９０１２３４５６７８９０１２３４５６７８９０");
    mvaddwstr(2, 0,  L"12345678901234567890123456789012345678901234567890123456789012345678901234567890");
    mvaddwstr(3, 0,  L"123あいうえお456かきくけこ789さしすせそ012たちつてと345なにぬねの678はひふへほ90");

    mvaddwstr(6, 5,  L"αβλ");
    mvaddwstr(7, 5,  L"〇△□");
    mvaddwstr(8, 5,  L"\U0001F525\U0001F363\U0001F431"); // 炎 寿司 猫

    mvaddwstr(LINES - 4, 0,  L"あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやいゆえよ");
    mvaddwstr(LINES - 3, 0,  L"１２３４５６７８９０１２３４５６７８９０１２３４５６７８９０１２３４５６７８９０");
    mvaddwstr(LINES - 2, 0,  L"12345678901234567890123456789012345678901234567890123456789012345678901234567890");
    mvaddwstr(LINES - 1, 0,  L"123あいうえお456かきくけこ789さしすせそ012たちつてと345なにぬねの678はひふへほ90");

    mvprintw(10, 0, "COLS=%d", COLS);
    mvprintw(11, 0, "LINES=%d", LINES);

    // 画面リフレッシュ
    refresh();

    // キー入力待ち
    getchar();

    // 終了処理
    endwin();

    return 0;
}
