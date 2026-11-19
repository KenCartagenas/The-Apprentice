#include "../../includes/component/MapElements.h"

namespace MapElements {
    const std::unordered_map<std::string, Vector2> tileCoordinates = {
        {"grass1", {1,1}},
        {"grass2", {2,1}},
        {"grass3", {1,2}},
        {"grass4", {2,2}},
        {"grass5", {3,2}},
        {"grass6", {4,2}},
        {"grass7", {5,2}},
        {"grass8", {6,2}},
        {"soil", {1,7}},
        {"topLeftSoil", {2,7}},
        {"topRightSoil", {3,7}},
        {"bottomLeftSoil", {5,7}},
        {"bottomRightSoil", {1,8}}
    };
}