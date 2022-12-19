#ifndef _CONSTS_H_
#define _CONSTS_H_

// Standards library for windows

//Using windows compilers for windows
#ifndef WIN32
#ifndef __BORLANDC__
#error Using with operating system Windows XP or higher. 
#else
#pragma message "Compiler BCB Builder"
#define WIN32 __WIN32__
#endif
#endif

#endif /* _CONSTS_H_ */
