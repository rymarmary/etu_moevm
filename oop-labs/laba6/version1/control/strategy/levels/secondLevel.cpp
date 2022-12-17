#include "secondLevel.h"

Field *secondLevel::generateLevel() {
    return generator.createField();
}
