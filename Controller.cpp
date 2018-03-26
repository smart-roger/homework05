#include "Controller.h"

void Controller::setUI(std::shared_ptr<UI> newUI){
		_ui = newUI;

		if(nullptr == _doc){
            DocHelper helper;
			_doc=helper.createNewDoc("");
		}

		_ui->setController(this);
}

void Controller::onCreate(std::string settings){
	    DocHelper helper;
		_doc = helper.createNewDoc(settings);
		_ui->update();
}
