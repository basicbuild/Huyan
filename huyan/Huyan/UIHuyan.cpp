
#include "UIHuyan.h"
#include <QVBoxLayout>
#include <QSlider>
#include "UIToolButton.h"
#include "CGammaRamp.h"
#ifdef _WIN32
#include <windows.h>
#pragma execution_character_set("utf-8")
#endif
#include <winuser.h>
#define MIN_VOLUME 64
#define MAX_VOLUME 156
#define SIGNAL_STEP 2

UIHuyan::UIHuyan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}

UIHuyan::~UIHuyan()
{
}

void UIHuyan::initUI()
{
	QVBoxLayout* _vlayoutMain = new QVBoxLayout(this);
	 
	QLabel *_lbeTip = new QLabel(tr("累计保护您的眼睛：15分钟/2小时"), this);

	// 亮度调节
	QLabel* _lbeDimming = new QLabel(tr("亮度调节"), this);
	QSlider* m_sliderDimming;
	m_sliderDimming = new QSlider(this);
	m_sliderDimming->setObjectName("micVolumeSlider");
	m_sliderDimming->setOrientation(Qt::Horizontal);  // 水平方向
	m_sliderDimming->setMinimum(MIN_VOLUME);  // 最小值
	m_sliderDimming->setMaximum(MAX_VOLUME);  // 最大值
	m_sliderDimming->setSingleStep(SIGNAL_STEP);  // 步长
	m_sliderDimming->setFixedWidth(200);
	connect(m_sliderDimming, &QSlider::valueChanged, this, &UIHuyan::on_slider_bright_activated);

	// 智能护眼
	QLabel* _lbeSmarteyeprotection = new QLabel(tr("智能护眼"), this);
	QSlider* m_sliderSmarteyeprotection;
	m_sliderSmarteyeprotection = new QSlider(this);
	m_sliderSmarteyeprotection->setObjectName("micVolumeSlider");
	m_sliderSmarteyeprotection->setOrientation(Qt::Horizontal);  // 水平方向
	m_sliderSmarteyeprotection->setMinimum(MIN_VOLUME);  // 最小值
	m_sliderSmarteyeprotection->setMaximum(MAX_VOLUME);  // 最大值
	m_sliderSmarteyeprotection->setSingleStep(SIGNAL_STEP);  // 步长
	m_sliderSmarteyeprotection->setFixedWidth(200);

	// 颜色调节
	QLabel* _lbeColorAdjustment = new QLabel(tr("颜色调节"), this);

	QHBoxLayout* _hlayoutColorAdjustment = new QHBoxLayout(this);

	UIToolButton* _uiToolButton1 = new UIToolButton(tr("推荐模式"), tr(":/huyan/image_view_icon"), this);
	UIToolButton* _uiToolButton2 = new UIToolButton(tr("阅读模式"), tr(":/huyan/image_view_icon"), this);
	UIToolButton* _uiToolButton3 = new UIToolButton(tr("强光模式"), tr(":/huyan/image_view_icon"), this);
	UIToolButton* _uiToolButton4 = new UIToolButton(tr("黑夜模式"), tr(":/huyan/image_view_icon"), this);
	UIToolButton* _uiToolButton5 = new UIToolButton(tr("游戏模式"), tr(":/huyan/image_view_icon"), this);

	connect(_uiToolButton1, SIGNAL(pressed()), this, SLOT(on_mouse_press()));
	connect(_uiToolButton2, SIGNAL(pressed()), this, SLOT(on_mouse_press()));
	connect(_uiToolButton3, SIGNAL(pressed()), this, SLOT(on_mouse_press()));
	connect(_uiToolButton4, SIGNAL(pressed()), this, SLOT(on_mouse_press()));
	connect(_uiToolButton5, SIGNAL(pressed()), this, SLOT(on_mouse_press()));

	_hlayoutColorAdjustment->addWidget(_uiToolButton1);
	_hlayoutColorAdjustment->addWidget(_uiToolButton2);
	_hlayoutColorAdjustment->addWidget(_uiToolButton3);
	_hlayoutColorAdjustment->addWidget(_uiToolButton4);
	_hlayoutColorAdjustment->addWidget(_uiToolButton5);

	_vlayoutMain->addWidget(_lbeTip, 0, Qt::AlignHCenter);
	_vlayoutMain->addWidget(_lbeDimming, 0, Qt::AlignLeft);
	_vlayoutMain->addWidget(m_sliderDimming, 0, Qt::AlignLeft);
	_vlayoutMain->addWidget(_lbeSmarteyeprotection, 0, Qt::AlignLeft);
	_vlayoutMain->addWidget(m_sliderSmarteyeprotection, 0, Qt::AlignLeft);
	_vlayoutMain->addWidget(_lbeColorAdjustment, 0, Qt::AlignLeft);
	_vlayoutMain->addLayout(_hlayoutColorAdjustment);
	
	setLayout(_vlayoutMain);
}

void UIHuyan::on_slider_bright_activated(int _bright)
{
	CGammaRamp GammaRamp;

	//Make the screen darker:
	GammaRamp.SetBrightness(NULL, _bright);

}

void UIHuyan::on_slider_color_activated(int _color)
{
}

void UIHuyan::on_mouse_press()
{

	CGammaRamp GammaRamp;

	//Make the screen darker:
	GammaRamp.SetBrightness(NULL, 0,155,34);

	//DEVMODE lpDevMode;
	//lpDevMode.dmBitsPerPel = 24;
	//lpDevMode.dmPelsWidth = 800;
	//lpDevMode.dmPelsHeight = 600;
	//lpDevMode.dmSize = sizeof(lpDevMode);
	//lpDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
	//LONG result;
	//result = ChangeDisplaySettings(&lpDevMode, 0);
	//if (result == DISP_CHANGE_SUCCESSFUL)
	//{
	//	ChangeDisplaySettings(&lpDevMode, CDS_UPDATEREGISTRY);
	//	//使用CDS_UPDATEREGISTRY表示次修改是持久的，
	//	//并在注册表中写入了相关的数据 
	//}
	//else
	//{
	//	ChangeDisplaySettings(NULL, 0);
	//}


}
