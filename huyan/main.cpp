#include "huyan.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>
#include "UITitleBar.h"

QString _get_qss_content(const QString& _path)
{/// 读取本地qss文件中内容，存储在QString字符串中
	QString _qss = "";
	QSettings* _settings = new QSettings(_path, QSettings::IniFormat);

	int index = 1;
	while (true)
	{
		QString param = "StyleSheet/" + QString::number(index);
		QString style_path = _settings->value(param).toString();
		if (!style_path.isEmpty())
		{
			QFile file(style_path);
			QString qss_content;

			file.open(QIODevice::ReadOnly);
			qss_content = file.readAll();
			_qss += qss_content;

			file.close();
		}
		else
			break;

		index++;
	}

	delete _settings;
	_settings = nullptr;
	return _qss;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    huyan w;
    w.show();
    //UITitleBar w;
    //w.show();
	qApp->setStyleSheet(_get_qss_content(":/huyan/res/skins/stylesheet.ini"));
    return a.exec();
}
