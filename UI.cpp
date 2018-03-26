#include "UI.h"
void UI::createDoc(std::string settings){
    _controller->onCreate(settings);
}

//- импорт документа из файла
void UI::importDoc(std::string fileFrom){
	    _controller->onImport(fileFrom);
}

	//- экспорт документа в файл
void UI::exportDoc(std::string fileTo){
	    _controller->onExport(fileTo);
}

void UI::shapeCreate(Shape::shapeType type, std::vector<Shape::param> params){
    _controller->onCreateShape(type, params);
}

void UI:: shapeRemove(std::shared_ptr<Shape> shapeRemove){
        _controller->onDeleteShape(shapeRemove);
}

void UI::update(){
    render(_controller->currentDoc());
}
