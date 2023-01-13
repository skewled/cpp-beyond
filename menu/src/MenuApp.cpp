#include <memory>
#include <menu/Menu.h>

using namespace std;
using namespace ui;

class ShowCmd : public Command
{
	public:
		void operator()(MenuItem& mi) override
	{
		cout << mi.Title() << " selected" << endl;
	}
};

class QuitCmd : public Command
{
	public:
		void operator()(MenuItem& mi) override
	{
		cout << "Bye" << endl;
		exit(0);
	}
};

void ShowFunc(MenuItem& mi)
{
	cout << mi.Title() << " selected" << endl;
}

void QuitFunc(MenuItem&)
{
	exit(0);
}

int main()
{
	ShowCmd show;
	QuitCmd quit;

	bool running = true;

	Menu mainMenu("Main Menu");
	// note - Menu has an AddItem overload that accepts a 
	// std::initializer_list.  The compiler will automatically create one
	// when a list of objects is enclosed in { } 
	mainMenu.AddItem({MenuItem("Add Shape", show), // Command Pattern CLass
					MenuItem("Show Area", ShowFunc), // Functor, must be stateless... Adapter Pattern
					MenuItem("Show Perimeter", [](MenuItem& mi){ cout << "Perimeter" << endl;}), // Lambda execution, access to mainMenu, show, and quit!
					MenuItem("Quit", [&running](MenuItem&){ running = false;})});

	// alternative is to use a variadic template.  Note no {}
	//mainMenu.AddItem(MenuItem("Add Shape", show),
	//				MenuItem("Show Area", show),
	//				MenuItem("Show Perimeter", show),
	//				MenuItem("Quit", quit));

	while(running) mainMenu.Show();
    return 0;
}

