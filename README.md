*Introduction*
1. Make sure your have sourced scripts/config before starting.
2. Create a directory with your name.
3. cd to your directory and work on your course project.
4. Write a README.md markdown file stating the title of your course project.
5. During the work you'll update it with description of your project.

No need for encryption of your files. Always create them in your own directory.

*Instuctions on keypress input*

Use <input.h> library for asynchronous key-press reading.

1. Call cbreak() to setup.
2. Call keypress() to retrieve the pressed character (-1, if nothing pressed).
3. Call normal() to reset for normal stdin reading.

**Example Program**

<pre><code>#include &ltiostream&gt
#include &ltstring&gt

#include &ltinput.hpp&gt

int main()
{
	std::cout << "Press 'w' or 'q'. " << std::endl;

	cbreak();

	while (true) {
		const char key = keypress();
		switch (key) {
		case 'w': case 'W':
			std::cout << "w pressed" << std::endl;
			break;
		case 'q':
			std::cout << "q pressed. Quitting." << std::endl;
			goto EXIT;
		}
	}
EXIT:
	normal();

	std::string name;
	std::cout << "Your name: ";
	std::cin >> name;
	std::cout << "By, " << name << '!' << std::endl;
	return 0;
}</code></pre>

**Compilation**

Save it in a sample file sample.cpp and compile it by adding -llibinput.o option:
`g++ -o sample sample.cpp -llibinput.o`

Now run it:
`./sample`

In generale add "-llibinput.o" to the end of your filelist":

`g++ -o <exe name\> <file1.cpp file2.cpp file3.cpp ...> -llibinput.o`

