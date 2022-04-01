#pragma once

#include <map>
#include <string>

namespace Jynx {
	struct Keys {
		int BACKSPACE = 8;
		int TAB = 9;
		int ENTER = 10;
		int ESCAPE = 27;
		int SPACE = 32;
		int INSERT = 458961534;
		int DELETE = 458961790;
		int HOME = 1792840;
		int END = 1792838;
		int PAGE_UP = 458962302;
		int PAGE_DOWN = 458962558;
		
		int LEFT = 1792836;
		int RIGHT = 1792835;
		int UP = 1792833;
		int DOWN = 1792834;

		int F1  =    1789776; int SHIFT_F1  = 825963088; int CTRL_F1  = 825963856; 
		int F2  =    1789777; int SHIFT_F2  = 825963089; int CTRL_F2  = 825963857;
		int F3  =    1789778; int SHIFT_F3  = 825963090; int CTRL_F3  = 825963858;
		int F4  =    1789779; int SHIFT_F4  = 825963091; int CTRL_F4  = 825963859;
		int F5  = 1529951614; int SHIFT_F5  = 893071998; int CTRL_F5  = 893072766;
		int F6  = 1529952126; int SHIFT_F6  = 926626430; int CTRL_F6  = 926627198;
		int F7  = 1529952382; int SHIFT_F7  = 943403646; int CTRL_F7  = 943404414;
		int F8  = 1529952638; int SHIFT_F8  = 960180862; int CTRL_F8  = 960181630;
		int F9  = 1530015870; int SHIFT_F9  = 809185918; int CTRL_F9  = 809186686;
		int F10 = 1530016126; int SHIFT_F10 = 825963134; int CTRL_F10 = 825963902;
		int F11 = 1530016638; int SHIFT_F11 = 859517566; int CTRL_F11 = 859518334;
		int F12 = 1530016894; int SHIFT_F12 = 876294782; int CTRL_F12 = 876295550;

		int CTRL_SHIFT_F1  = 825964112;	int ALT_SHIFT_F1  = 825963600;
    int CTRL_SHIFT_F2  = 825964113; int ALT_SHIFT_F2  = 825963601;
    int CTRL_SHIFT_F3  = 825964114; int ALT_SHIFT_F3  = 825963602;
    int CTRL_SHIFT_F4  = 825964115; int ALT_SHIFT_F4  = 825963603;
    int CTRL_SHIFT_F5  = 893073022; int ALT_SHIFT_F5  = 893072510;
    int CTRL_SHIFT_F6  = 926627454; int ALT_SHIFT_F6  = 926626942;
    int CTRL_SHIFT_F7  = 943404670; int ALT_SHIFT_F7  = 943404158;
    int CTRL_SHIFT_F8  = 960181886; int ALT_SHIFT_F8  = 960181374;
    int CTRL_SHIFT_F9  = 809186942; int ALT_SHIFT_F9  = 809186430;
    int CTRL_SHIFT_F10 = 825964158; int ALT_SHIFT_F10 = 825963646;
    int CTRL_SHIFT_F11 = 859518590; int ALT_SHIFT_F11 = 859518078;
    int CTRL_SHIFT_F12 = 876295806; int ALT_SHIFT_F12 = 876295806;

		int CTRL_A =  1;	int ALT_A = 7009;	int CTRL_ALT_A = 6913;
		int CTRL_B =  2;	int ALT_B = 7010;	int CTRL_ALT_B = 6914;
		int CTRL_C =  3;	int ALT_C = 7011;	int CTRL_ALT_C = 6915;
		int CTRL_D =  4;	int ALT_D = 7012;	int CTRL_ALT_D = 6916;
		int CTRL_E =  5;	int ALT_E = 7013;	int CTRL_ALT_E = 6917;
		int CTRL_F =  6;	int ALT_F = 7014;	int CTRL_ALT_F = 6918;
		int CTRL_G =  7;	int ALT_G = 7015;	int CTRL_ALT_G = 6919;
		int CTRL_H =  8;	int ALT_H = 7016;	int CTRL_ALT_H = 6920;
		int CTRL_I =  9;	int ALT_I = 7017;	int CTRL_ALT_I = 6921;
		int CTRL_J = 10;	int ALT_J = 7018;	int CTRL_ALT_J = 6922;
		int CTRL_K = 11;	int ALT_K = 7019;	int CTRL_ALT_K = 6923;
		int CTRL_L = 12;	int ALT_L = 7020;	int CTRL_ALT_L = 6924;
		int CTRL_M = 13;	int ALT_M = 7021;	int CTRL_ALT_M = 6925;
		int CTRL_N = 14;	int ALT_N = 7022;	int CTRL_ALT_N = 6926;
		int CTRL_O = 15;	int ALT_O = 7023;	int CTRL_ALT_O = 6927;
		int CTRL_P = 16;	int ALT_P = 7024;	int CTRL_ALT_P = 6928;
		int CTRL_Q = 17;	int ALT_Q = 7025;	int CTRL_ALT_Q = 6929;
		int CTRL_R = 18;	int ALT_R = 7026;	int CTRL_ALT_R = 6930;
		int CTRL_S = 19;	int ALT_S = 7027;	int CTRL_ALT_S = 6931;
		int CTRL_T = 20;	int ALT_T = 7028;	int CTRL_ALT_T = 6932;
		int CTRL_U = 21;	int ALT_U = 7029;	int CTRL_ALT_U = 6933;
		int CTRL_V = 22;	int ALT_V = 7030;	int CTRL_ALT_V = 6934;
		int CTRL_W = 23;	int ALT_W = 7031;	int CTRL_ALT_W = 6935;
		int CTRL_X = 24;	int ALT_X = 7032;	int CTRL_ALT_X = 6936;
		int CTRL_Y = 25;	int ALT_Y = 7033;	int CTRL_ALT_Y = 6937;
		int CTRL_Z = 26;	int ALT_Z = 7034;	int CTRL_ALT_Z = 6938;
	};

	struct Input {
		int getkey(bool echo = false);
		int waitfor(int key, bool echo = false);
		std::string getline();
	};
}
