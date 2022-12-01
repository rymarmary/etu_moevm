#include "firstLevel.h"


Field *firstLevel::generateLevel() {
    return generator.createField();
}
