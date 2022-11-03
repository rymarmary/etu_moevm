#include "fieldView.h"

fieldView::fieldView(Field &field) : field(field) {}

void fieldView::printField() {
    std::cout << '\n';
    for (int i = 0; i <= field.getWidth(); i++)
        std::cout << " - ";
    std::cout << "\n";
    for (int j = 0; j < field.getHeight(); ++j) {
        std::cout << "|";
        for (int k = 0; k < field.getWidth(); ++k)
            std::cout << cellView(field.getCells().at(j).at(k)).getOption() << "  ";
        std::cout << " |\n"; // можно убрать пробел
    }
    for (int i = 0; i <= field.getWidth(); i++)
        std::cout << " - ";
    std::cout << "\n";
}