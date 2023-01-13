#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <algorithm>

namespace ui
{
	class MenuItem;

	class Command
	{
		public:
			virtual void Selected(MenuItem& mi) = 0;
			virtual ~Command() {}
	};

	class MenuItem
	{
	public:
		MenuItem(std::string text, Command& cmd) : text(text), cmd(cmd) {}
		void Select() { cmd.Selected(*this); }
		std::string Title() const { return text; }
	private:
		std::string text;
		// Store the command object by reference, must initalize it in initializer list in constructor
		Command& cmd;
	};
    typedef std::unique_ptr<MenuItem> MenuItemUp;
	
	class Menu
	{
	public:
		Menu(std::string title) : heading(title) {}
		void AddItem(const MenuItem& mi)
		{
			items.push_back(std::make_unique<MenuItem>(mi));
		}

		void AddItem(std::initializer_list<MenuItem> items)
		{
			std::for_each(items.begin(), items.end(), 
				[this] (auto item){AddItem(item);});
		}
		// this variadic template utilizes C++ 17 (-std=c++17) 
		// feature called folding.
		// the folding repeats the AddItem for each item in the pack
		// this feature is discussed in our advanced c++ course
		template <typename... MenuItems>
		void AddItem (const MenuItems&... mi)
		{
			(AddItem(mi), ...);
		}		
	

		int Show() const;

	private:
		//void AddItem(){}
		std::string heading;
		std::vector<MenuItemUp> items;
	};


}