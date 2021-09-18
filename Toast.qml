import QtQuick 2.11
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.3
import "."
import "."

Rectangle {
    function show(text, duration, isGood) {
        message.text = text.toUpperCase();
        good = isGood;
        time = defaultTime;
        animation.start();
    }

    property bool selfDestroying: false  // whether this Toast will self-destroy when it is finished
    property bool good: false
    color: good ? "#09242F" : "#09242F"
    border.color:  good ?  "#01F3F7" : "#C34141"
    border.width: 2
    /**
      * Private
      */

    id: root
    readonly property real defaultTime: 3000
    property real time: defaultTime
    property real fadeTime: 300

    property real margin: 10

    anchors {
        left: parent.left
        right: parent.right
        leftMargin: 10
        rightMargin: 10
    }

    height: 90
    width: parent.width
    radius: 5

    opacity: 0
    Image {
        id: close
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 5
        source: "qrc:/close_bright.svg"
        fillMode: Image.PreserveAspectFit
        sourceSize.width: 8
        sourceSize.height: 8
        ColorOverlay{
            anchors.fill: parent
            source: close
            color: good ?  "#01F3F7" : "#C34141"
        }
        MouseArea{
            anchors.fill: close
            onClicked: {
                animation.stop()
                fadeTime = 10
                time = 2 * fadeTime
                animation.start()
            }
        }
    }

    //    Image {
    //        id: icon
    //        anchors.top: parent.top
    //        anchors.left: parent.left
    //        anchors.margins: 5
    //        source: "qrc:/ui/image/infotoast.svg"
    //        fillMode: Image.PreserveAspectFit
    //        sourceSize.width: 4
    //        sourceSize.height: 13
    //        MouseArea{
    //            anchors.fill: icon
    //            onClicked: {
    //                root.destroy()
    //            }
    //        }

    //    }


    Rectangle{
        anchors.fill: parent
        anchors.leftMargin: 15
        anchors.topMargin: parent.height / 10
        anchors.bottomMargin: parent.height / 10
        anchors.rightMargin: 15
        color: "transparent"
        ColumnLayout{
            anchors.fill: parent
            spacing: 2
            Label {
                id: info
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                Layout.preferredHeight: 1
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                color: good ?  "#01F3F7" : "#C34141"
                text: "THÔNG BÁO"
                font.bold: true
                font.pointSize: 12
            }
            Label {
                id: message
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                Layout.preferredHeight: 1.5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                color: "white"
                wrapMode: Text.WordWrap
                font.bold: true
                font.pointSize: 12
            }
        }
    }




    SequentialAnimation on opacity {
        id: animation
        running: false


        NumberAnimation {
            to: .9
            duration: fadeTime
        }

        PauseAnimation {
            duration: time - 2 * fadeTime
        }

        NumberAnimation {
            to: 0
            duration: fadeTime
        }

        onRunningChanged: {
            if (!running && selfDestroying) {
                root.destroy();
            }
        }
    }
}
