#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "UI.h"
#include "DocHelper.h"
#include "Document.h"
#include "TShapeBuilder.h"

/*!
Класс для основного контроллера
*/

class UI;
class Document;

/*! Определение интерфейса для контроллера. Разделение интерфейса и реализации.*/
class TControllerIface{
public:
    virtual void setUI(std::shared_ptr<UI> newUI) = 0;
    virtual std::shared_ptr<Document>   currentDoc() = 0;

	virtual void onCreate(std::string settings) = 0;
	virtual void onImport(std::string settings)=0;
	virtual void onExport(const std::string& settings)= 0;
	virtual void onCreateShape(Shape::shapeType type, std::vector<Shape::param> params) = 0;
	virtual void onDeleteShape(std::shared_ptr<Shape> shapeRemove) = 0;

	virtual ~TControllerIface(){};
};

/*! Реализация контроллера с описанным интерфейсом.
*/
class Controller : public TControllerIface{
    //  Обрабатываемый документ
	std::shared_ptr<Document>	_doc;
    //  Привязанный UI
	std::shared_ptr<UI>		_ui;

	public:
	Controller():TControllerIface(), _doc(nullptr), _ui(nullptr){};
	virtual ~Controller(){};

	/*! Связывание UI и контроллера*/
	void setUI(std::shared_ptr<UI> newUI);

	/*! Связывание контроллера и документа*/
	void setDocument(sharedDocumentPtr newDoc){
		_doc = newDoc;
	};

	/*! Возвращение указателя на объект. Используется для отрисовки объекта в UI*/
	std::shared_ptr<Document>   currentDoc(){return _doc;};

	//создание нового документа
	void onCreate(std::string settings);

	//- импорт документа из файла
	void onImport(std::string settings){
		DocHelper   importer;
		_doc = importer.ImportDoc(settings);
	};

	//- экспорт документа в файл
	void onExport(const std::string& settings){
	    DocHelper exporter;
		exporter.ExportDoc(_doc, settings);
	};

	//- создание графического примитива
	void onCreateShape(Shape::shapeType type, std::vector<Shape::param> params){
        std::cout << "Create shape. " << std::endl;
        TShapeBuilder shapeBuilder;
        shapeBuilder.setShapeType(type);
        for(param : params){
            shapeBuilder.setParam(param.first, param.second);
        }

        _doc->addShape(shapeBuilder.getShape());

	};

	//  Удаление фигуры
	void onDeleteShape(std::shared_ptr<Shape> shapeRemove){
	    _doc->removeShape(shapeRemove);
        std::cout << "Delete shape. " << std::endl;
	};//- удаление графического примитива
};

using uniqControllerPtr = std::unique_ptr<Controller>;
using sharedControllerPtr = std::shared_ptr<Controller>;

#endif
