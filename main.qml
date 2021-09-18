import QtQuick 2.12
import QtQuick.Window 2.12
import "."
import Flux 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyButton {
        id: buttonStart
        anchors.fill: parent
        anchors.topMargin: parent.height * 5 / 100
        anchors.bottomMargin: parent.height * 85 / 100
        anchors.leftMargin: parent.width * 50/100
        anchors.rightMargin: parent.width * 2 /100
        buttonName: "Start"

        onClicked: {
            ActionProvider.startApp()
        }
    }

    MyButton {
        id: buttonStop
        anchors.fill: parent
        anchors.topMargin: parent.height * 20 / 100
        anchors.bottomMargin: parent.height * 70 / 100
        anchors.leftMargin: parent.width * 50/100
        anchors.rightMargin: parent.width * 2 /100
        buttonName: "Stop"

        onClicked: {
            ActionProvider.stopApp()
        }
    }

    MyButton {
        id: buttonReset
        anchors.fill: parent
        anchors.topMargin: parent.height * 35 / 100
        anchors.bottomMargin: parent.height * 55 / 100
        anchors.leftMargin: parent.width * 50/100
        anchors.rightMargin: parent.width * 2 /100
        buttonName: "Reset"

        onClicked: {
            ActionProvider.resetApp()
        }
    }

    ToastManager{
        id: toastManager
        anchors.topMargin: parent.height * 40 / 100
        anchors.bottomMargin: parent.height * 12 / 100
        anchors.leftMargin: parent.width * 1/100
        anchors.rightMargin: parent.width * 50 /100
    }

    Connections {
        target: CommonStore
        onStateIdle:
        {
            var messageText = "IDLE STATE";
            toastManager.show(messageText, 8000, true);
        }

        onStateStart:
        {
            var messageText = "START STATE";
            toastManager.show(messageText, 8000, true);
        }

        onStateStop:
        {
            var messageText = "STOP STATE";
            toastManager.show(messageText, 8000, true);
        }
    }
}
