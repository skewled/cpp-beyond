

namespace training::geometry 
{
    template <typename T>
    void Show(const T& c)
    {
        std::cout << c << std::endl;
    }

    template <typename T, class... Args>
    void Show(const T& c, const Args&... args)
    {
        Show(c);
        Show(args...);
    }
}