#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QGroupBox>
#include <QComboBox>
#include <QTimer>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <iostream>
#include <QFileDialog>
#include <QDataStream>
#include "SpeechInput.h"
#include "Sort.h"
#include "Tool.h"
#include "DSLFunctionSort.h"
#include "NaturalLanguageToDSL.h"
#include "GifRecorder.h"


using namespace std;



class SortWidget : public QWidget {
    Q_OBJECT

public:
    SortWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建界面组件

        ///////////////初始化
        ItemX=50;
        ItemY=50;





        /////////////////////////////////////////////////////////////左侧控制区

        //序列输入框
        QLabel *numLabel = new QLabel("序列:");
        numstrEdit = new QTextEdit();
        numstrEdit->setFixedHeight(30);
        //延时输入框
        QLabel *delayLabel = new QLabel("延时:");
        delayEdit = new QLineEdit("1000");
        delayEdit->setFixedHeight(30);

        //按钮
        QPushButton *sortButton = new QPushButton("排序");
        QPushButton *clearButton = new QPushButton("清除");
        //选择
        chooseBox = new QComboBox();
        QLabel *chooseLabel = new QLabel("算法:");
        chooseBox->addItem("请选择算法");
        chooseBox->addItem("直接插入排序");
        chooseBox->addItem("简单选择排序");
        chooseBox->addItem("快速排序");
        chooseBox->setFixedWidth(210);
        chooseBox->setFixedHeight(30);
        //布局
        QHBoxLayout *numInputLayout = new QHBoxLayout();
        QHBoxLayout *chooseLayout = new QHBoxLayout();
        QVBoxLayout *controlLayout = new QVBoxLayout();
        controlLayout->setSpacing(20);//设置layout中元素间距
        QGroupBox *controlGroup = new QGroupBox("控制区");

        //序列输入区
        numInputLayout->addWidget(numLabel);
        numInputLayout->addWidget(numstrEdit);
        QGroupBox *numInputGroup = new QGroupBox("序列输入区");
        numInputGroup->setLayout(numInputLayout);
        controlLayout->addWidget(numInputGroup);

        //算法选择区
        chooseLayout->addWidget(chooseLabel);
        chooseLayout->addWidget(chooseBox);
        chooseLayout->addStretch(1);
        QGroupBox *chooseGroup = new QGroupBox("算法选择区");
        chooseGroup->setLayout(chooseLayout);
        controlLayout->addWidget(chooseGroup);

        //速度设置区
        QHBoxLayout *delayLayout = new QHBoxLayout();
        delayLayout->addWidget(delayLabel);
        delayLayout->addWidget(delayEdit);
        QGroupBox *delayGroup = new QGroupBox("设置延时区");
        delayGroup->setLayout(delayLayout);
        controlLayout->addWidget(delayGroup);

        //文件保存读取
        savefileButton = new QPushButton("保存文件");
        readfileButton = new QPushButton("打开文件");
        QHBoxLayout *fileLayout = new QHBoxLayout();
        fileLayout->addWidget(savefileButton);
        fileLayout->addWidget(readfileButton);

        //DSL
        QLabel *DSLLabel = new QLabel("DSL");
        DSLEdit = new QTextEdit();
        DSLEdit->setFixedHeight(100);
        DSLButton = new QPushButton("DSL执行");
        QVBoxLayout *DSLInputLayout = new QVBoxLayout();
        DSLInputLayout->addWidget(DSLLabel);
        DSLInputLayout->addWidget(DSLEdit);
        QVBoxLayout *DSLLayout = new QVBoxLayout();
        DSLLayout->addLayout(DSLInputLayout);
        DSLLayout->addWidget(DSLButton);

        //语音
        voiceButton = new QPushButton("按住说话");
        voiceButton->setToolTip("按住开始说，松开停止并转文字");

        //自然语言
        QLabel *naturalLabel = new QLabel("自然语言");
        naturalEdit = new QTextEdit();
        naturalEdit->setFixedHeight(100);
        naturalButton = new QPushButton("自然语言执行");
        QVBoxLayout *naturalInputLayout = new QVBoxLayout();
        naturalInputLayout->addWidget(naturalLabel);
        naturalInputLayout->addWidget(naturalEdit);
        QVBoxLayout *naturalLayout = new QVBoxLayout();
        naturalLayout->addLayout(naturalInputLayout);
        naturalLayout->addWidget(naturalButton);

        QHBoxLayout* languageLayout = new QHBoxLayout();
        languageLayout-> addLayout(DSLLayout);
        languageLayout->addLayout(naturalLayout);
        QGroupBox * languageGroup = new QGroupBox("DLS & 自然语言");
        languageGroup->setLayout(languageLayout);



        //排序和清除按钮水平排列
        QHBoxLayout * ButtonLayout = new QHBoxLayout();
        ButtonLayout->addWidget(sortButton);
        ButtonLayout->addWidget(clearButton);
        ButtonLayout->addWidget(voiceButton);


        //左边总布局
        controlLayout->addWidget(languageGroup);
        controlLayout->addLayout(ButtonLayout);
        controlLayout->addLayout(fileLayout);
        controlLayout->addStretch(1);

        controlGroup->setLayout(controlLayout);



        /////////////////////////////////////////////////////////////右侧观看区
        QVBoxLayout *viewLayout = new QVBoxLayout();

        //可视化区域
        QLabel *graphLabel = new QLabel("图形可视化区域");
        graphView= new QGraphicsView();
        scene= new QGraphicsScene(this);
        graphView->setScene(scene);
        graphView->setRenderHint(QPainter::Antialiasing);

        //序列输出框
        QHBoxLayout *resultLayout = new QHBoxLayout();
        QLabel *resultLabel = new QLabel("结果:");
        resultEdit = new QTextEdit();
        resultEdit->setFixedHeight(30);
        resultEdit->setReadOnly(true); // 结果框设为只读

        //用时输出框
        QLabel *timetLabel = new QLabel("用时:");
        QLabel *msLabel = new QLabel("ms");
        timeEdit = new QTextEdit();
        timeEdit->setFixedHeight(30);
        timeEdit->setReadOnly(true);


        resultLayout->addWidget(resultLabel);
        resultLayout->addWidget(resultEdit);
        resultLayout->addWidget(timetLabel);
        resultLayout->addWidget(timeEdit);
        resultLayout->addWidget(msLabel);

        viewLayout->addWidget(graphLabel);
        viewLayout->addWidget(graphView);
        viewLayout->addLayout(resultLayout);


        ////////////////////////////////////////////////////////////（总）排序算法演示区
        QHBoxLayout *Layout = new QHBoxLayout();
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QLabel *titleLabel = new QLabel("排序算法演示");
        titleLabel->setAlignment(Qt::AlignCenter);

        Layout->addWidget(controlGroup,1);//拉伸因子
        Layout->addLayout(viewLayout,3);//拉伸因子

        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(Layout);






        //////////////////////////////////////////////////////////// 连接按钮点击信号到槽函数
        Sort* sort = new Sort();
        connect(sortButton, QPushButton::clicked, this, &SortWidget::submitData);
        connect(sort, &Sort::usingTime, this, &SortWidget::DisplayTime);
        connect(this, &SortWidget::sendData, sort, &Sort::getData);
        connect(sortButton, QPushButton::clicked, this, &SortWidget::creatGraph);
        connect(clearButton, QPushButton::clicked, this, &SortWidget::ClearAll);
        connect(sort, &Sort::numSwap, this, &SortWidget::RectSwap);
        connect(sort, &Sort::setColor, this, &SortWidget::SetRectColor);

        connect(savefileButton, QPushButton::clicked, this, &SortWidget::saveFile);
        connect(readfileButton, QPushButton::clicked, this, &SortWidget::openFile);

        //DSL连接
        DSLSort *dslsort = new DSLSort();
        connect(DSLButton, QPushButton::clicked, this, &SortWidget::executeDSL);
        connect(this, &SortWidget::sendDataDSL, dslsort, &DSLSort::execute);
        connect(dslsort, DSLSort::sendSEQ, this, &SortWidget::DSLcreatSEQ);
        connect(dslsort, DSLSort::sendSelectSort, this, &SortWidget::DSLSelectSort);

        //自然语言
        ntod = new NaturalLanguageToDSL();
        connect(naturalButton, QPushButton::clicked, this, &SortWidget::executeNatural);
        connect(this, &SortWidget::sendNatural, ntod, &NaturalLanguageToDSL::execute);
        connect(ntod, NaturalLanguageToDSL::sendDSL, this, &SortWidget::showNaturalToDSL);

        //语音输入
        connect(voiceButton, QPushButton::pressed,  this, &SortWidget::onVoicePressed);
        connect(voiceButton, QPushButton::released, this, &SortWidget::onVoiceReleased);

        //gif
        gifRecorder = new GifRecorder(this);
        gifRecorder->setTarget(graphView);
        connect(sort, &Sort::usingTime, this, &SortWidget::onSortFinishedAskSaveGif);




    }
    ~SortWidget() {
        speech.stop();
    }


signals:
    void sendData(QString,int,int);
    void sendDataDSL(const string&);
    void applyAPI();
    void sendNatural(string);


public slots:

    //gif
    void onSortFinishedAskSaveGif(QString /*usingtime*/) {
        if (!demoRunning) return;
        demoRunning = false;

        if (!gifRecorder) return;

        gifRecorder->stop();

        if (gifRecorder->tempFilePath().isEmpty()) {
            // 没录到/没生成临时文件
            return;
        }

        auto ret = QMessageBox::question(
            this,
            "保存动画",
            "演示已结束，是否保存为 GIF 动画？",
            QMessageBox::Yes | QMessageBox::No
        );

        if (ret == QMessageBox::Yes) {
            QString dst = QFileDialog::getSaveFileName(
                this,
                "保存GIF动画",
                "",
                "GIF 动画 (*.gif)"
            );

            if (!dst.isEmpty()) {
                if (!dst.endsWith(".gif", Qt::CaseInsensitive)) dst += ".gif";

                bool ok = gifRecorder->saveAs(dst);
                if (ok) QMessageBox::information(this, "成功", "GIF 动画保存成功！");
                else    QMessageBox::warning(this, "失败", "GIF 动画保存失败！");
            }
        }

        gifRecorder->discardTemp();
    }

    //语音输入
    void onVoicePressed() {
        voiceButton->setText("松开结束");

        // 开始持续听写（按住期间不断累积片段）
        speech.startHold(
            this,
            [this](const QString& text) {
                // 松开后的最终文字写入自然语言输入框
                naturalEdit->setText(text);
                voiceButton->setText("按住说话");
            },
            [this](const QString& err) {
                voiceButton->setText("按住说话");
                QMessageBox::warning(this, "语音识别失败", err);
            }
        );
    }

    void onVoiceReleased() {
        voiceButton->setText("按住说话");
        speech.stop(true); // 停止并输出最终文本
    }

    void setSpeechCred(QString appid, QString token) {
        speech.setCredential(appid, token);
    }




    //自然语言相关
    void setAPI(QString getapi) {
        APIkey = getapi;
        ntod->setApiKey(APIkey);
    }

    void executeNatural() {
        emit sendNatural(naturalEdit->toPlainText().toStdString());

    }

    void showNaturalToDSL(QString str) {
        DSLEdit->setText(str);
        executeDSL();
    }

    //DSL相关
    void executeDSL() {
        const string& code = DSLEdit->toPlainText().toStdString();
        emit sendDataDSL(code);
    }

    void DSLcreatSEQ(QString str) {
        numstrEdit -> setText(str);
        creatGraph();
    }

    void DSLSelectSort(QString str) {
        if (str == "IS") {
            chooseBox->setCurrentIndex(1);
        }else if (str == "SS") {
            chooseBox->setCurrentIndex(2);
        }else if (str == "QS") {
            chooseBox->setCurrentIndex(3);
        }
        submitData();
    }

    void DisplayTime(QString usingtime) {
        timeEdit->setText(usingtime);
    }

    void submitData() {

        QString numstring = numstrEdit->toPlainText();
        QString chooseType = chooseBox->currentText();
        int delay =delayEdit->text().toInt();
        int sortType=0;
        if (chooseType == "请选择算法") {
            sortType = 0;
        }else if (chooseType == "直接插入排序") {
            sortType = 1;
        }else if (chooseType == "简单选择排序") {
            sortType = 2;
        }else if (chooseType == "快速排序") {
            sortType = 3;
        }


        if (sortType != 0) {
            demoRunning = true;
            if (gifRecorder && graphView && graphView->viewport()) {
                int interval = qBound(30, delay / 10, 120);
                gifRecorder->setTarget(graphView);
                gifRecorder->start(interval);
            }
        }


        emit sendData(numstring,sortType,delay);


    }

    void creatGraph() {

         if (!rectList.isEmpty()) {
             ClearRectAndResult();
        }


        //字符串转为数组并获取元素个数
        QString sortstr = numstrEdit->toPlainText();
        int isnum1=0;
        int count=0;
        for (int i = 0; i < sortstr.length(); i++) {
            QChar ch = sortstr.at(i);
            if (ch.isDigit() && isnum1 == 0) {
                count++;
                isnum1=1;
            }else if (!ch.isDigit()){isnum1=0;}
        }

        int isnum2=0;
        size=count;
        for (int i = 0,j=0; i < sortstr.length(); i++) {
            QChar ch2 = sortstr.at(i);
            if (ch2.isDigit() && isnum2 == 0) {
                arr[j]=ch2.digitValue();
                isnum2=1;
            }
            else if (ch2.isDigit() && isnum2 == 1){
                arr[j]=arr[j]*10+ch2.digitValue();
            }
            else if(!ch2.isDigit()){isnum2=0;j++;;}
        }



         //创建图形
         for (int i=0; i < count; i++,ItemX=ItemX+50) {
             // 创建矩形顶点
             rectItem = new QGraphicsRectItem(ItemX, ItemY, 50, 20*arr[i]);
             rectItem->setTransform(QTransform::fromScale(1, -1), true);
             rectList.append(rectItem);
             rectLocation.append(make_pair(ItemX,ItemY));
             scene->addItem(rectList.operator[](i));


             // 创建文本标签
             textItem = new QGraphicsTextItem(QString::number(arr[i]));
             textItem->setPos(ItemX+18,ItemY-90);
             rectLabelsList.append(textItem);
             scene->addItem(rectLabelsList.operator[](i));


         }

        ItemX=50;
        ItemY=50;


    }

    void ClearAll() {

        demoRunning = false;
        if (gifRecorder && gifRecorder->isRecording()) gifRecorder->stop();
        if (gifRecorder) gifRecorder->discardTemp();


            while (!rectList.isEmpty()) {
                delete rectList.takeAt(0);
            }

            while (!rectLabelsList.isEmpty()) {
                delete rectLabelsList.takeAt(0);
            }

            numstrEdit->clear();
            timeEdit->clear();
            resultEdit->clear();
            rectLocation.clear();


    }

    void RectSwap(int n,int m,int s,int type) {
        int x=rectLocation[m].first,y=rectLocation[m].second;

        if (s==0) {
            ChangeRectAnimation(rectList.operator[](m),type,n*20,20*arr[m],x,y,delayEdit->text().toInt()/10);
            arr[m]=n;
            rectLabelsList.operator[](m)->setPlainText(QString::number(n));
        }else if (s==1) {
            ChangeRectAnimation(rectList.operator[](m),type,20*arr[n],20*arr[m],x,y,delayEdit->text().toInt()/10);
            arr[m]=arr[n];
            rectLabelsList.operator[](m)->setPlainText(QString::number(arr[n]));
        }


        Displayresult();
    }

    void SetRectColor(int num,int s) {
        if (s==0) {
            rectList.operator[](num)->setBrush(QBrush(Qt::transparent));
        }else if (s==1) {
            rectList.operator[](num)->setBrush(QBrush(Qt::green));
        }else if (s==2) {
            rectList.operator[](num)->setBrush(QBrush(Qt::red));
        }else if (s==3) {
            rectList.operator[](num)->setBrush(QBrush(Qt::darkGreen));
        }else if (s==4) {
            rectList.operator[](num)->setBrush(QBrush(Qt::blue));
        }


    }

    bool saveData(const QString &fileName) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "错误", "无法创建文件！");
            return false;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_15);

        // 写入文件标识
        out << QString("GRAPH_SORT_V1.0");
        qDebug() << "写入文件标识完成，数据流状态:" << out.status();

        out << numstrEdit->toPlainText();
        qDebug() << "保存数组";

        file.close();
        qDebug() << "文件保存完成";
        return true;
    }

    void saveFile() {
        QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "", "可视化文件 (*.wyxsort)");
        if (!fileName.isEmpty()) {
            if (!fileName.endsWith(".wyxsort", Qt::CaseInsensitive)) {
                fileName += ".wyxsort";
            }
            if (saveData(fileName)) {
                QMessageBox::information(this, "成功", "文件保存成功！");
            }
        }
    }

    bool loadData(const QString &fileName) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "错误", "无法打开文件！");
            return false;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_15);

        // 读取文件标识
        QString fileTag;
        in >> fileTag;
        qDebug() << "文件标识:" << fileTag << "，数据流状态:" << in.status();

        if (fileTag != "GRAPH_SORT_V1.0") {
            QMessageBox::warning(this, "错误", "文件格式不正确！");
            file.close();
            return false;
        }

        QString arrtext;
        in >> arrtext;
        numstrEdit->setPlainText(arrtext);
        qDebug() << "读取数组";


        file.close();
        qDebug() << "文件加载完成";
        return true;
    }

    void openFile() {
        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "", "可视化文件 (*.wyxsort)");
        if (!fileName.isEmpty()) {
            if (loadData(fileName)) {
                QMessageBox::information(this, "成功", "文件读取成功！");
                ClearRectAndResult();
                creatGraph();
            }
        }
    }



private:
    void ClearRectAndResult() {
        while (!rectList.isEmpty()) {
            delete rectList.takeAt(0);
        }

        while (!rectLabelsList.isEmpty()) {
            delete rectLabelsList.takeAt(0);
        }

        timeEdit->clear();
        resultEdit->clear();
        rectLocation.clear();

    }

    void Displayresult() {
        resultEdit->setText(arrtoqs(arr,size));
    }


private:
    QTextEdit *numstrEdit;
    QTextEdit *resultEdit;
    QLineEdit *delayEdit;
    QGraphicsView *graphView;
    QGraphicsScene *scene;
    QComboBox *chooseBox;
    QTextEdit *timeEdit;
    QList<QGraphicsRectItem*> rectList;
    QList<QGraphicsTextItem*> rectLabelsList;
    QGraphicsRectItem *rectItem;
    QGraphicsTextItem *textItem;
    QList<pair<int,int> > rectLocation;
    int ItemX;
    int ItemY;
    int arr[100];
    int size;

    QPushButton *savefileButton;
    QPushButton *readfileButton;

    QPushButton *DSLButton;
    QTextEdit *DSLEdit;
    QPushButton *naturalButton;
    QTextEdit *naturalEdit;

    NaturalLanguageToDSL* ntod;
    QString APIkey;

    // 语音输入
    SpeechInput speech;
    QPushButton* voiceButton = nullptr;

    GifRecorder* gifRecorder = nullptr;
    bool demoRunning = false;



};

#include "main.moc"

#endif //SORTWIDGET_H



// 设置输入验证器，只允许输入数字和小数点
// QDoubleValidator *validator = new QDoubleValidator(this);
// numEdit->setValidator(validator);