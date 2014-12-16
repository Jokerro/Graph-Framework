#include "mainwindow.h"
#include <qdebug.h>
#include "graphwidget.h"

#include "httprequest.h"
#include <QSize>
#include <QMessageBox>
#include <QList>

int Graph::first_selected = 0;
int Graph::second_selected = 0;

QLabel* MainWindow::vertexInfo =0;
QLabel* MainWindow::edgeInfo =0;
bool GraphWidget::_isWeightVisible = false;
MainWindow::MainWindow(QWidget *parent, Graph* gr) :
    QMainWindow(parent)
{
    btnGo = new QPushButton("Go", this);
    connect(btnGo, SIGNAL(released()), this, SLOT(pressGo()));
    btn3Drender = new QPushButton("3D", this);
    connect(btn3Drender, SIGNAL(released()), this, SLOT(press3d()));
    cbPlay = new QCheckBox("Physics", this);
    connect(cbPlay, SIGNAL(released()), this, SLOT(selectPlay()));
    cbAntialiasing = new QCheckBox();
    connect(cbAntialiasing, SIGNAL(released()),this, SLOT(selectAntialiasing()));
    cbWeight = new QCheckBox();
    connect(cbWeight, SIGNAL(released()), this, SLOT(selectShowHideWeight()));


   // viewport = NULL;
    graph=gr;

    btnDFS = new QPushButton("DFS",this);
    connect(btnDFS, SIGNAL(released()), this, SLOT(pressDFS()));

    btnBFS = new QPushButton("BFS",this);
    connect(btnBFS, SIGNAL(released()), this, SLOT(pressBFS()));
    btnStong = new QPushButton("Strong components",this);

    connect(btnStong, SIGNAL(released()), this, SLOT(strong_handler()));
    btnGo->setBaseSize(100, 23);
    btnDFS->setBaseSize(100, 23);
    btnBFS->setBaseSize(100, 23);
    btnStong->setBaseSize(100, 23);

    connect(btnStong, SIGNAL(released()), this, SLOT(pressStrong()));

    tlId = new QTextLine();
    teId = new QTextEdit();
    QSize teIdSize = teId->document()->size().toSize();
    teIdSize.setWidth(100);
    teIdSize.setHeight(23);
    teId->setMaximumSize(teIdSize);
    cbAntialiasing->setText("Antialiasing");
    cbAntialiasing->setChecked(true);
    cbPlay->setChecked(true);
    cbWeight->setText("Show weight");
    cbWeight->setChecked(false);

    vertexInfo=new QLabel("Vertices:     ");
    edgeInfo=new QLabel("Edges:          ");
    toolBar = new QToolBar;
    toolBar->addWidget(teId);
    toolBar->addWidget(btnGo);
    toolBar->addSeparator();

    toolBar->addWidget(cbPlay);
    toolBar->addWidget(cbAntialiasing);
    toolBar->addWidget(cbWeight);
    toolBar->addSeparator();

    toolBar->addWidget(btn3Drender);
    toolBar->addWidget(btnDFS);
    toolBar->addWidget(btnBFS);
    toolBar->addWidget(btnStong);
    toolBar->addSeparator();
    toolBar->addWidget(vertexInfo);
    toolBar->addWidget(edgeInfo);

    this->addToolBar(toolBar);\
}


void MainWindow::createLabels(){
    vertexInfo=new QLabel("Vertexes: ");
    edgeInfo=new QLabel("Edges: ");
}





void MainWindow::updateLabels(int vert, int ed){
    vertexInfo->setText("Vertices: "+QString::number(vert)+"    ");
    edgeInfo->setText("Edges: "+QString::number(ed));
}

void MainWindow::selectAntialiasing(){

    if(cbAntialiasing->isChecked())
        graphWidget->setAntialiasingEnable(true);
    else
        graphWidget->setAntialiasingEnable(false);
}

void MainWindow::selectShowHideWeight(){
    if(cbWeight->isChecked())
        GraphWidget::setWeightVisible(true);
    else
        GraphWidget::setWeightVisible(false);
    graphWidget->itemMoved();
    graphWidget->scene()->update(-20000, -20000, 40000, 40000);
}

void MainWindow::setGraph(Graph* t)
{
    graph=t;
}


void MainWindow::setGraphWidget(GraphWidget *widget){
    graphWidget = widget;

}

void MainWindow::pressBFS()
{
    if(Graph::first_selected==0||Graph::second_selected==0)
        QMessageBox::information(NULL,"No selected vertexes", "Please, select two vertexes, before pushing this button");
    else
    {
        this->graph->resetGraph();

        QList<int> *vertexes = new QList<int>;
        this->graph->BFS(Graph::first_selected,Graph::second_selected,vertexes);

        for(int i=0;i<vertexes->size();i++)
        {
            for(int j=0;j<graph->getVertexList().size();j++)
            {
                if(graph->getVertexList()[j][0]->GetUserId()==vertexes->at(i))
                {
                    for(int k=0;k<this->graph->getVertexList()[j][0]->getNode()->edges().size();k++)
                    {
                       if(
                               ((this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].source->getTrueId()==vertexes->at(i))&&(this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].dest->getTrueId()==vertexes->at(i+1))) ||
                               ((this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].dest->getTrueId()==vertexes->at(i))&&(this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].source->getTrueId()==vertexes->at(i+1)))
                          )
                       {this->graph->getVertexList()[j][0]->getNode()->edges()[k]->color=Qt::red;
                        this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->update();}
                    }
                }
            }
        }



        Graph::second_selected=0;
        Graph::first_selected =0;
    }
}

void MainWindow::pressDFS()
{
    //qDebug()<<this->graph->test();
    if(Graph::first_selected==0||Graph::second_selected==0)
        QMessageBox::information(NULL,"No selected vertexes", "Please, select two vertexes, before pushing this button");
    else
    {
        this->graph->resetGraph();

        QList<int> *vertexes = new QList<int>;
        this->graph->DFS(Graph::first_selected,Graph::second_selected,vertexes);

        qDebug()<<"s1";

        for(int i=0;i<vertexes->size();i++)
        {
            for(int j=0;j<graph->getVertexList().size();j++)
            {
                if(graph->getVertexList()[j][0]->GetUserId()==vertexes->at(i))
                {
                    for(int k=0;k<this->graph->getVertexList()[j][0]->getNode()->get_edges().size();k++)
                    {
                       if(
                               ((this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].source->getTrueId()==vertexes->at(i))&&(this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].dest->getTrueId()==vertexes->at(i+1))) ||
                               ((this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].dest->getTrueId()==vertexes->at(i))&&(this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].source->getTrueId()==vertexes->at(i+1)))
                          )
                       {
                           this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->color=Qt::red;
                           this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->update();
                        }
                    }
                }
            }
        }

        QMessageBox::information(NULL,"Успех",QString::number(this->graph->getVertexList().size()));

        Graph::second_selected=0;
        Graph::first_selected =0;
    }
}


void MainWindow::pressGo(){

    QString str="http://api.vk.com/method/users.get?user_ids="+teId->toPlainText()+"&fields=photo_100,country,city&v=5.27";
    qDebug()<<str;
    req = new HttpRequest();
    req->processRequest(str, graph, teId->toPlainText().toInt(), req);
    updateLabels(graph->getVertexCount(), graph->getEdgeCount());
}

void MainWindow::pressStrong(){
    QList<QList<int> >  components;

    for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++)
        this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->resetEdges();

    graph->getStrongComponents(&components);
    int col=8;
    for(int i=0;i<components.size();i++)
    {
        paintComponent(components[i], col);
        col++;
    }
}

void MainWindow::paintComponent(QList<int> component, int color ){
    for(int i=0;i<component.size();i++)
    {
        for(int j=0;j<graph->getVertexList().size();j++)
        {
            if(graph->getVertexList()[j][0]->GetId()==component[i])
            {
                for(int k=0;k<this->graph->getVertexList()[j][0]->getNode()->edges().size();k++)
                {
                    if(this->graph->getVertexList()[j][0]->getNode()->edges()[k][0].dest->getTrueId()==graph->getVertexList()[j][0]->GetUserId())
                    {this->graph->getVertexList()[j][0]->getNode()->edges()[k]->color=Qt::GlobalColor(color);}
                }
        }
    }
}


for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++)
    this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->edges()[0]->update();
}

void MainWindow::selectPlay(){
    //action here
    if(graphWidget->isPhysicsDisabled())
        graphWidget->setPhysicsEnable(false);
    else
        graphWidget->setPhysicsEnable(true);

}
void MainWindow::press3d(){
//    qDebug()<<graphWidget->geoLocation->isFinished();
//    if (graphWidget->geoLocation->isFinished()){
//        if (viewport == NULL)
//            viewport = new ModelView();
//        viewport->setGraph(graph);
//        viewport->showMaximized();
//    }else{
//        QMessageBox::information(NULL,"Ожидайте!","Коордиаты друзей ещё не получены!");
//    }
}

MainWindow::~MainWindow()
{

}
