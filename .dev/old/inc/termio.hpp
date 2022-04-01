#pragma once

#include <string>
#include <termios.h>
#include <unistd.h>

namespace Jynx {
	struct Termio {
		struct attr  {
			char mode;
			int attr;
			bool operator()();
			void operator=(bool flag);
		};
		
		struct cc  {
			int attr;
			char operator()();
			void operator=(char new_char);
		};
	
		//iflags
		attr ignbrk = {'i', IGNBRK};
		attr brkint = {'i', BRKINT};
		attr ignpar = {'i', IGNPAR};
		attr parmrk = {'i', PARMRK};
		attr inpck  = {'i',  INPCK};
		attr istrip = {'i', ISTRIP};
		attr inlcr  = {'i',  INLCR};
		attr igncr  = {'i',  IGNCR};
		attr icrnl  = {'i',  ICRNL};
		attr ixon   = {'i',   IXON};
		attr ixoff  = {'i',  IXOFF};
		attr ixany  = {'i',  IXANY};

		//oflags
		attr opost  = {'o', IGNBRK};
		attr onclr  = {'o', ONLCR};
		attr ocrnl  = {'o', OCRNL};
		attr onocr  = {'o', ONOCR};
		attr onlret = {'o', ONLRET};
		attr ofill  = {'o', OFILL};
		attr nldly  = {'o', NLDLY};
		attr crdly  = {'o', CRDLY};
		attr tabdly = {'o', TABDLY};
		attr bsdly  = {'o', BSDLY};
		attr vtdly  = {'o', VTDLY};
		attr ffdly  = {'o', FFDLY};

		//cflags
		attr csize  = {'c',  CSIZE};
		attr cstopb = {'c', CSTOPB};
		attr cread  = {'c',  CREAD};
		attr parenb = {'c', PARENB};
		attr parodd = {'c', PARODD};
		attr hupcl  = {'c',  HUPCL};
		attr clocal = {'c', CLOCAL};

		//lflag
		attr isig   = {'l',   ISIG};
		attr icanon = {'l', ICANON};
		attr xcase  = {'l',  XCASE};
		attr echo   = {'l',   ECHO};
		attr echoe  = {'l',  ECHOE};
		attr echok  = {'l',  ECHOK};
		attr echonl = {'l', ECHONL};
		attr noflsh = {'l', NOFLSH};
		attr tostop = {'l', TOSTOP};
		attr iexten = {'l', IEXTEN};

		//cc
		cc veof     = {    VEOF};
		cc veol     = {    VEOL};
		cc verase   = {  VERASE};
		cc vintr    = {   VINTR};
		cc vkill    = {   VKILL};
		cc vlnext   = {  VLNEXT};
		cc vmin     = {    VMIN};
		cc vquit    = {   VQUIT}; 
		cc vreprint = {VREPRINT}; 
		cc vstart   = {  VSTART}; 
		cc vstop    = {   VSTOP}; 
		cc vsusp    = {   VSUSP}; 
		cc vtime    = {   VTIME}; 
	};
}
