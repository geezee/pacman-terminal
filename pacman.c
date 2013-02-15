/**
 *	A simple program that prints a pacman and some ghosts
 *	inside the terminal, it doesn't depend on anything
 *	but requires the file 'ansi.sys' to be installed
 *	which is installed on most Linux distros
 *
 *	Author recommends that you add it to the bashrc file
 *	To display that image when you open the terminal for coolness
 *	purposes (PS: your hard-core friends will be jealous)
 *
 *	@author George Zakhour <g1995z@gmail.com> http://george.zakhour.me
 *	@version 0.1 Build on Feb 14, 2012
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef char* string; // to make life easier
string blocks(int s, string b); // generate s blocks of b next to eachothers
string pacman(int line); // returns the line representation of a line of pacman
string ghost(string color, int line); // like pacman but returns a ghost given a certain color



/* Library of all the colors used,
	yellow, white, lightred, light cyan,
	light blue, brown, green
*/
string yellow = "\033[01;33m";
string white = "\033[01;37m";
string red = "\033[01;31m";
string cyan = "\033[01;36m";
string blue = "\033[01;34m";
string magenta = "\033[22;35m";
string green = "\033[22;32m";

// feel free to change the character that is used
// to draw the pacmans and the ghosts, and to change the
// seperator, by default the seperator is " " and the block
// is "B"
string b = "8";
string s = " ";




/**
 *	Start of the program, draws row by row
 *	everything untill the image is drawn,
 *	uses as colors the above string representation
 *
 *	@return		int 0, to end the program
 */
int main() {

	// print everything
	int line;
	printf("\n");
	for(line=1;line<8;line++) {
		printf("%s%s%s%s%s\n",pacman(line),ghost(green,line),
		ghost(cyan,line),ghost(magenta,line),ghost(red,line));
	}
	printf("%s\n",white); // reset the color and skip a line
	return 0;
}

/**
 *	Builds a block of s b characters
 *	next to each other and returns
 *	that string,
 *	Example: blocks(5,"*") returns *****
 *
 *	@param int s		number of characters to print
 *	@param string b		characters to print
 *	@return			b typed s times
 */
string blocks(int s, string b) {
	int m;
	// initialize the string
	string output = (string)malloc(100000);
	strcpy(output,"");
	for(m=0;m<s;m++)
		strcat(output,b);
	return output;
}


/**
 *	returns the string representation of a pacman along
 *	a given line, it uses the b and s variable initialized above
 *
 *	@param int line		which line to return the representation of
 *	@return			line representation
 */
string pacman(int line) {
	string m = (string)malloc(10000000);
	int n;

	if(line == 1)
		sprintf(m,"%s%s%s%s",yellow,blocks(5,s),blocks(7,b),blocks(7,s));
	else if(line == 2)
		sprintf(m,"%s%s%s%s",yellow,blocks(2,s),blocks(13,b),blocks(4,s));
	else if(line == 3)
		sprintf(m,"%s%s%s%s",yellow,blocks(1,s),blocks(7,b),blocks(11,s));
	else if(line == 4)
		sprintf(m,"%s%s%s%s",yellow,blocks(1,s),blocks(3,b),blocks(15,s));
	else if(line == 5)
		sprintf(m,"%s%s%s%s",yellow,blocks(1,s),blocks(7,b),blocks(11,s));
	else if(line == 6)
		sprintf(m,"%s%s%s%s",yellow,blocks(2,s),blocks(13,b),blocks(4,s));
	else if(line == 7)
		sprintf(m,"%s%s%s%s",yellow,blocks(5,s),blocks(7,b),blocks(7,s));
	else
		sprintf(m,""); 
	return m;
}


/**
 *	returns the string representatoin of a ghost along
 *	a given line, it uses the b and s variable initialized above
 *
 *	@param string c		the color of the ghost
 *	@param int line		which line to return the representation of
 *	@return 		line representation
 */
string ghost(string c, int line) {
	string m = (string)malloc(1000000);
	int n;

	if(line == 1)
		sprintf(m,"%s%s%s%s",
		c,blocks(5,s),blocks(3,b),blocks(8,s));
	else if(line == 2)
		sprintf(m,"%s%s%s%s",
		c,blocks(2,s),blocks(9,b),blocks(5,s));
	else if(line == 3)
		sprintf(m,"%s%s%s%s%s%s%s%s%s%s%s%s",
		c,blocks(1,s),blocks(2,b),white,blocks(2,b),
		c,blocks(5,b),white,blocks(2,b),c,blocks(1,b),
		blocks(3,s));
	else if(line == 4)
		sprintf(m,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		c,blocks(2,b),white,blocks(2,b),blue,blocks(2,b),
		c,blocks(3,b),white,blocks(2,b),blue,blocks(2,b),
		c,blocks(1,b),blocks(2,s));
	else if(line == 5)
		sprintf(m,"%s%s%s%s%s%s%s%s%s%s%s",
		c,blocks(3,b),white,blocks(2,b),c,blocks(5,b),
		white,blocks(2,b),c,blocks(2,b),blocks(2,s));
	else if(line == 6)
		sprintf(m,"%s%s%s",c,blocks(14,b),blocks(2,s));
	else if(line == 7)
		sprintf(m,"%s%s%s%s%s%s%s%s%s",c,blocks(1,b),
		blocks(3,s),blocks(2,b),blocks(3,s),blocks(2,b),
		blocks(2,s),blocks(1,b),blocks(2,s));
	else
		sprintf(m,"");
	return m;
}
