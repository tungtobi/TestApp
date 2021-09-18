import QtQuick 2.11
import QtQuick.Controls 2.2
import QtQml.StateMachine 1.11 as DSM
import QtGraphicalEffects 1.12
import "."

Button {
    id: button
    implicitHeight: 70
    implicitWidth: 70

    property var definedPosition : ({
                                        "Top":0,
                                        "Bottom":1,
                                        "Left":2,
                                        "Right":3
                                    })
    property int imagePosition: definedPosition.Right
    property string imageSource: ""
    property string buttonName: ""
    property bool isVisible: true
    property bool isFinished: false
    property bool isType1 : true
    property int textSize: isType1 ? 14 : 13
    property int btnRadius: 5

    // Color for state of button: button color, border color, text color
    // disable
    property color disableButtonColor: "#132233"
    property color disableBorderColor: "#08ECDE"
    property color disabletextColor: "#B5B4B0"

    // enter
    readonly property color enteredButtonColor:  isType1 ? "#08ECDE": "#02FEFD"
    readonly property color enteredBorderColor:  isType1 ?"#08ECDE" : "#02FEFD"
    readonly property color enteredtextColor:  isType1 ?"#132233": "#02FEFD"

    // idle
    property color idleButtonColor: isType1? "#02FEFD" : "transparent"
    property color idleBorderColor: isType1? "#02FEFD" : "#02FEFD"
    property color idletextColor: isType1? "#132233" : "#02FEFD"

    // press
    readonly property color pressButtonColor: "#08ECDE"
    readonly property color pressBorderColor: "#08ECDE"
    readonly property color presstextColor: isType1? "#132233" : HmiDefines.gray_50

    visible: isVisible

    activeFocusOnTab : true
    background: Rectangle {
        id: btn
        anchors.fill: parent
        radius: btnRadius
        color: idleButtonColor
        border.color: idleBorderColor
        LinearGradient{
            anchors.fill: parent
            anchors.margins: 2
            visible: !isType1
            gradient: Gradient{
                GradientStop{position: 0; color:   "#2C626B"   }
                GradientStop{position: 1.0; color: "#1A4A58" }
            }
        }


        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                stateMachine.processEvent("evEntered")
            }
            onExited: {
                stateMachine.processEvent("evExited")
            }
            onClicked: {
                //console.log("onClicked")
            }

            onPressed: {
                stateMachine.processEvent("evPressed")
            }
            onReleased: {
                stateMachine.processEvent("evReleased")
            }

            onHoveredChanged: {
                //if(hovered)
                //console.log("onHovered")
            }
        }
    }

    Text {
        id: text
        text: buttonName
        anchors.fill: parent
        font.pointSize: textSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        //        anchors.left: imagePosition === definedPosition.Right ? parent.left : undefined
        //        anchors.leftMargin: image.width
        //        anchors.right: imagePosition === definedPosition.Left ? parent.right : undefined
        //        anchors.rightMargin: image.width
        color: idletextColor
        wrapMode: Text.WordWrap
        font.bold: true
        padding: 5
    }


    DSM.StateMachine {
        id: stateMachine
        initialState: button.enabled ? idleState : disableState
        running: true
        signal evEntered()
        signal evExited()
        signal evReleased()
        signal evPressed()
        signal evStartFocus()
        signal evStopFocus()
        signal evDisable()
        signal evEnable()

        function processEvent(event) {
            switch(event) {
            case "evEntered":
                evEntered()
                break
            case "evExited":
                evExited()
                break
            case "evReleased":
                evReleased()
                button.clicked()
                break
            case "evPressed":
                evPressed()
//                button.pressed()
                break
            case "evStartFocus":
                evStartFocus()
                break
            case "evStopFocus":
                evStopFocus()
                break
            case "evDisable":
                evDisable()
                break
            case "evEnable":
                evEnable()
                break
            }
        }


        DSM.State {
            id: idleState

            DSM.SignalTransition{
                targetState: enteredState
                signal: stateMachine.evEntered
                onTriggered: {
//                    console.log("idle->entered")
                }
            }

            DSM.SignalTransition{
                targetState: enteredState
                signal: stateMachine.evStartFocus
                onTriggered: {
//                    console.log("idle->entered")
                }
            }

            DSM.SignalTransition {
                targetState: disableState
                signal: stateMachine.evDisable
                onTriggered: {
//                    console.log("enable->disable")
                }
            }

            onEntered: {
                btn.color = idleButtonColor
                btn.border.color = idleBorderColor
                text.color = idletextColor
            }
        }

        DSM.State {
            id: enteredState
            DSM.SignalTransition{
                targetState: idleState
                signal: stateMachine.evExited
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evPressed]: entered->idle")
                }
            }

            DSM.SignalTransition {
                targetState: disableState
                signal: stateMachine.evDisable
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evDisable]: enable->disable")
                }
            }

            DSM.SignalTransition{
                targetState: idleState
                signal: stateMachine.evStopFocus
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evStopFocus]: entered->idle")
                }
            }

            DSM.SignalTransition{
                targetState: pressedState
                signal: stateMachine.evPressed
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evPressed]: entered->pressed")
                }
            }

            onEntered: {
                btn.color = enteredButtonColor
                btn.border.color = enteredBorderColor
                text.color = enteredtextColor
            }
        }

        DSM.State {
            id: pressedState
            DSM.SignalTransition{
                targetState: enteredState
                signal: stateMachine.evReleased
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evReleased]: pressed->entered")
                }
            }

            onEntered: {
                btn.color = pressButtonColor
                btn.color = pressBorderColor
                text.color = presstextColor
            }
        }

        DSM.State {
            id: disableState
            DSM.SignalTransition{
                targetState: idleState
                signal: stateMachine.evEnable
                onTriggered: {
//                    console.log("onTriggered[stateMachine.evEnable]: disable->enable")
                }
            }

            onEntered: {
                btn.color = disableButtonColor
                btn.border.color = disableBorderColor
                text.color = disabletextColor
            }
        }
    }

    onVisualFocusChanged: {
        if (button.visualFocus) {
            stateMachine.processEvent("evStartFocus")
        } else {
            stateMachine.processEvent("evStopFocus")
        }
    }

    onEnabledChanged: {
        if(!enabled) {
            stateMachine.processEvent("evDisable")
        }else {
            stateMachine.processEvent("evEnable")
        }
    }

    Keys.onReturnPressed:  {
        //console.log("return press")
        stateMachine.processEvent("evPressed")
        keyTimer.start()
    }

    Keys.onSpacePressed:  {
        //        console.log("space press")
        stateMachine.processEvent("evPressed")
        keyTimer.start()
    }

    Timer {
        id: keyTimer
        interval: 50
        repeat: false
        onTriggered: {
            stateMachine.processEvent("evReleased")
            keyTimer.stop()
        }
    }


}
