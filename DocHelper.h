#include "Document.h"

/*!
Класс для работы с документом.
Введён для реализации импорта, экспорта документа
*/
class DocHelper{
	public:
	DocHelper(){};
	~DocHelper(){};

	/*!	Экспортирование документа*/
	void ExportDoc(sharedDocumentPtr doc, const std::string& params){
		//  Для подавления сообщения о неиспользуемых параметрах
		doc->setSettings(params);
		std::cout << "Export doc. " << params << std::endl;
	};

	/*!	Импортирование документа*/
	sharedDocumentPtr ImportDoc(const std::string& params){
		std::cout << "Import. " << params << std::endl;
		return std::make_shared<Document>(params);};

	/*!	Создание нового документа*/
	sharedDocumentPtr createNewDoc(const std::string& params){
		std::cout << "Create doc. " << params << std::endl;
		return std::make_shared<Document>(params);};
};
