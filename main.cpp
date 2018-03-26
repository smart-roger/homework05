
#include "Controller.h"
#include "UI.h"

/*!
	Запуск основной программы - только примеры
*/
int main(int argc, char const *argv[])
{
    //  GUI
	auto mainWindow = std::make_shared<UI>();
	//  Контроллер
	TControllerIface* _controller = new Controller;

	//  Связывание контроллера и GUI
	_controller->setUI(mainWindow);

	//  Демонстрация вызовов
	mainWindow->createDoc("New document");
	mainWindow->importDoc("import.file");
	mainWindow->shapeCreate(Shape::shapeType::Circle, {{"ceterX","10"},{"centerY","20"}, {"radius","100"}});
	mainWindow->shapeCreate(Shape::shapeType::Line, {{"x1","10"},{"y1","20"}, {"x2","100"}, {"y2", "20"}});
	mainWindow->shapeCreate(Shape::shapeType::Polygon, {{"x1","1"},{"y1","2"},{"x2","3"},{"y2","4"},{"x3","5"},{"y3","6"},{"color","red"}});
	mainWindow->show();
	mainWindow->exportDoc("export.file");

	//  Некрасиво, но надо для примера вызова удаления фигуры. Нужен указатель/id фигуры для удаления.
	auto _shapes = _controller->currentDoc()->shapes();
	mainWindow->shapeRemove(*_shapes.begin());

	return 0;
}
