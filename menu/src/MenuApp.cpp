#include <memory>
#include <menu/Menu.h>

using namespace std;
using namespace ui;

int main()
{
	Menu mainMenu("Main Menu");
	// note - Menu has an AddItem overload that accepts a 
	// std::initializer_list.  The compiler will automatically create one
	// when a list of objects is enclosed in { } 
	mainMenu.AddItem({"Add Shape", "Show Area", "Show Perimeter", "Quit"});

	// alternative is to use a variadic template.  Note no {}
	//mainMenu.AddItem("Add Shape", "Show Area", "Show Perimeter", "Quit");

	auto resp = mainMenu.Show();
	switch (resp)
	{
	case 1:
		cout << "Add selected" << endl;
		break;
	case 2:
		cout << "Area selected" << endl;
		break;
	case 3:
		cout << "Perimeter selected" << endl;
		break;
	case 4:
		cout << "quit" << endl;
		break;
	}
    return 0;
}

