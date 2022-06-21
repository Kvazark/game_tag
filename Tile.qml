import QtQuick 2.0

Rectangle {
    id: root;
    property string displayText: "";
    //readonly property alias internalText: _firstText;

    color: "lightblue";
    border.color: black;
    border.width: 1;
    radius: 10

    Text{
        id: _firstText;
        anchors.centerIn: root;
   //     x: root.width / 2 - width/2;
   //     y: root.height/2-height/2;
        text: root.displayText;
        font{
            pointSize: Math.min(root.width, root.height)/3;
            bold: true;
        }
    }
}
