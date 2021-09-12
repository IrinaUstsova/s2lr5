#include <iostream>
#include "QueueList.h"

bool IsEven(int i) {
    return !(bool)(i % 2);
}

int main() {
    size_t size = 10;
    int* a = new int[size];
    for (size_t i = 0; i < size; ++i) {
        a[i] = rand() % 100;
    }

    QueueList ql(a, size);

    // 1
    for (auto pos : ql) {
        std::cout << pos << " ";
    }
    std::cout << "\n";

    // 2
    for(auto &pos : ql){
        std::cout << ++pos << " ";
    }
    std::cout << "\n";

    // 3
    int elem;
    std::cout << "Enter element: "; std::cin >> elem;
    Iterator it = std::find(ql.begin(), ql.end(), elem);
    if (it == ql.end()) {
        std::cout << "No such item!\n";
    }
    else std::cout << *it << "\n";

    // 4
    std::cout << "Minimal element: " << *std::min_element(ql.begin(), ql.end()) << "\n";

    // 5
    std::cout << "Max element: " << *std::max_element(ql.begin(), ql.end()) << "\n";

    // 6
    std::cout << "Number of even elements: " << std::count_if(ql.begin(), ql.end(), IsEven) << "\n";

    // 7
    std::cout << "Enter element: "; std::cin >> elem;
    std::for_each(ql.begin(), ql.end(), [&elem](auto& i) { if (i > elem){ i += 10; }
        else { i -= 10; } });
    for (auto pos : ql) {
        std::cout << pos << " ";
    }

    return 0;
}
