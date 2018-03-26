#include "TShapeBuilder.h"
#include "Shape.h"

std::shared_ptr<Shape> TShapeBuilder::createShape(){
    sharedShapePtr  newShape;
    switch(_currentType){
        case Shape::shapeType::Line:{
            newShape = std::make_shared<Line>();
            break;
        }
        case Shape::shapeType::Polygon:{
            newShape = std::make_shared<Polygon>();
            break;
        }
        case Shape::shapeType::Circle:{
            newShape = std::make_shared<Circle>();
            break;
        }
    }
    std::for_each(_params.begin(), _params.end(), [newShape](auto param){
                newShape->setParam(param.first, param.second);
             });
    _params.clear();
    return newShape;
}
