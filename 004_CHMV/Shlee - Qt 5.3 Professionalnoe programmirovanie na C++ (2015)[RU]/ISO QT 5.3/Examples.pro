TEMPLATE = subdirs

defineTest(errorMessage) {
    message("Cannot build examples with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.3.0.")
}

!isEqual(QT_MAJOR_VERSION, 5) {
    errorMessage()
}
else : lessThan(QT_MINOR_VERSION, 3) {
    errorMessage()
}
else {
SUBDIRS       = chapter01/Hello \
                chapter02/Counter \
                chapter03/LibraryInfo \
                chapter05/Background \
                chapter05/MouseCursor \
                chapter05/ScrollArea \
                chapter06/AddStretch \
                chapter06/Calculator \
                chapter06/GridLayout \
                chapter06/HBoxLayout \
                chapter06/Layout \
                chapter06/Splitter \
                chapter06/Stretch \
                chapter06/VBoxLayout \
                chapter07/Label \
                chapter07/LabelBuddy \
                chapter07/LabelPixmap \
                chapter07/LCD \
                chapter07/LinkLabel \
                chapter07/Progress \
                chapter08/ButtonGroup \
                chapter08/ButtonPopup \
                chapter08/Buttons \
                chapter08/CheckBox \
                chapter08/RadioButton \
                chapter09/Dial \
                chapter09/ScrollBar \
                chapter09/Slider \
                chapter10/DateTimeEdit \
                chapter10/LineEdit \
                chapter10/SpinBox \
                chapter10/SyntaxHighlighter \
                chapter10/TextEdit \
                chapter10/Validator \
                chapter11/ComboBox \
                chapter11/IconMode \
                chapter11/ListWidget \
                chapter11/TableWidget \
                chapter11/TabWidget \
                chapter11/ToolBox \
                chapter11/TreeWidget \
                chapter12/FileSystemModel \
                chapter12/Explorer \
                chapter12/HierarchicalModel \
                chapter12/IntListModel \
                chapter12/ProxyModel \
                chapter12/Roles \
                chapter12/SelectionSharing \
                chapter12/SimpleDelegate \
                chapter12/TableModel \
                chapter12/WidgetAndView \
                chapter13/WidgetPalette \
                chapter14/MouseEvent \
                chapter14/ResizeEvent \
                chapter15/EventFilter \
                chapter16/EventChange \
                chapter16/EventSimulation \
                chapter18/GraphicsEffect \
                chapter18/CompositionModes \
                chapter18/ConicalGradient \
                chapter18/LinearGradient \
                chapter18/PainterPath \
                chapter18/RadialGradient \
                chapter19/TranslucentBackground \
                chapter19/ImageDraw \
                chapter19/Window \
                chapter19/ScanLine \
                chapter20/DrawText \
                chapter20/ElidedText \
                chapter20/GradientText \
                chapter21/CustomGraphicsView \
                chapter21/GraphicsView \
                chapter21/ProxyWidget \
                chapter22/States \
                chapter22/Movie \
                chapter22/ColorAnimation \
                chapter22/SvgAnimation \
                chapter22/EasingCurves \
                chapter24/Printer \
                chapter25/CustomWidget \
                chapter26/AppStyle \
                chapter26/CSSStyle \
                chapter26/CustomStyle \
                chapter26/MyLabel \
                chapter26/Styles \
                chapter27/SoundPlayer \
                chapter27/VideoPlayer \
                chapter28/Session \
                chapter28/Settings \
                chapter29/Drag \
                chapter29/Drop \
                chapter29/WidgetDragAndDrop \
                chapter31/ContextMenu \
                chapter31/Menu \
                chapter31/TearOffMenu \
                chapter32/InputDialog \
                chapter32/MessageBoxes \
                chapter32/StandardDialogs \
                chapter32/Wizard \
                chapter33/HelpBrowser \
                chapter33/CustomToolTip \
                chapter33/WhatsThis \
                chapter34/MDI \
                chapter34/SDI \
                chapter34/SplashScreen \
                chapter34/StatusBar \
                chapter34/ToolBar \
                chapter35/ScreenShot \
                chapter35/SystemTray \
                chapter36/FileFinder \
                chapter36/FileSystemWatcher \
                chapter37/BlinkLabel\
                chapter37/Clock \
                chapter38/Process \
                chapter38/ThreadEvent \
                chapter38/ThreadSignal \
                chapter38/ThreadTimer \
                chapter38/QtConcurrent \
                chapter38/QtConcurrent2 \
                chapter39/Downloader \
                chapter39/UdpClient \
                chapter39/UdpServer \
                chapter39/TcpClient \
                chapter39/TcpServer \
                chapter39/Client \
                chapter39/Server \
                chapter40/XmlStreamReader \
                chapter40/XQuery \
                chapter40/XmlDOMRead \
                chapter40/XmlDOMWrite \
                chapter40/XmlSAXRead \
                chapter41/SQL \
                chapter41/SqlRelationTableModel \
                chapter41/SQLQueryModel \
                chapter41/SQLTableModel \
		chapter42/DynLib/Application \
		chapter42/DynLib/DLL \
                chapter42/PlugIn/Application \
                chapter42/PlugIn/MyPlugIn \
                chapter43/MacButton \
                chapter44/LoadMyForm \
                chapter44/MyForm \
                chapter45/DataDrivenTest \
                chapter45/GuiTest \
                chapter45/TestLib \
                chapter46/SimpleView \
                chapter46/WebBrowser \
                chapter49/ZweiMalZwei \
                chapter52/SignalAndSlots \
                chapter52/Turtle \
                chapter52/Debug \
                chapter53/HelloQML \
                chapter54/CustomElement \
                chapter54/IdRefence \
                chapter54/OnWidthAndHeight \
                chapter54/Properties \
                chapter54/Rectangle \
                chapter54/OneControl \
                chapter54/Controls \
                chapter54/Dialogs \
                chapter55/Anchors \
                chapter55/AnchorsOver \
                chapter55/AnchorsStretch \
                chapter55/Anchors2 \
                chapter55/Grid \
                chapter55/Margins \
                chapter55/RowLayout \
                chapter56/BorderImage \
                chapter56/Gradients \
                chapter56/Image \
                chapter56/Canvas \
                chapter57/Button \
                chapter57/ButtonAlternative \
                chapter57/EnterAndExit \
                chapter57/HoverEvent \
                chapter57/KeysInput \
                chapter57/MouseArea \
                chapter57/Navigation \
                chapter57/Signals \
                chapter57/TextInput \
                chapter57/TwoTextEdits \
                chapter58/BehaviorAnimation \
                chapter58/ColorAnimation \
                chapter58/NumberAnimation \
                chapter58/ParallelAnimation \
                chapter58/PropertyAnimation \
                chapter58/RotationAnimation \
                chapter58/States \
                chapter58/Transitions \
                chapter58/SequentialAnimation \
                chapter59/Flickable \
                chapter59/GridView \
                chapter59/ListView \
                chapter59/PathViewLine \
                chapter59/PathViewQuad \
                chapter59/XMLModel \
                chapter60/CPPExtension \
                chapter60/Calculation \
                chapter60/ImageProvider \
                chapter60/QMLCPPUsage 

opengl {
    SUBDIRS +=  chapter23/OGLDraw \
                chapter23/OGLPyramid \
                chapter23/OGLQuad 
}

windows:SUBDIRS += chapter43/WinAPI 

}#Qt5.3 check
 