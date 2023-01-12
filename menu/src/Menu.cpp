#include <algorithm>
#include <menu/Menu.h>

namespace ui
{
    int Menu::Show() const
    {
        int sel;
        int i;
        do
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n"
                      << std::endl;
            std::cout << "------------------ " << heading << " ------------------" << std::endl
                      << std::endl;
            i = 1;
            std::for_each(items.begin(), items.end(), 
                [&i] (auto& mi) {std::cout << i++ << ") " << mi->Title() << std::endl;});
            i--;
            std::cout << "Enter selection (1-" << i << "): " << std::flush;
            std::string tmp;
            std::cin >> tmp;
            try {sel = std::stoi(tmp);} 
            catch(const std::invalid_argument&) {sel = -1;}
            sel--;
            if (sel >= 0 && sel < i)
                items[sel]->Select();
        } while (sel < 0 || sel >= i);
        return sel + 1;
    }
}