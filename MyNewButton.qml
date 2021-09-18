import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.2
import QtGraphicalEffects 1.12

Button {
    id: button
    height: 40
    width: 300
    property url activeImageUrl
    property url inActiveImageUrl
    property url disableImageUrl
    property bool isButtonDisable: false
    enabled: !isButtonDisable

    onEnabledChanged: {
        if (button.isButtonDisable)
        {
            image.source = disableImageUrl
        }
        else
        {
            if (mouseArea.containsMouse)
            {
                image.source = activeImageUrl
            }
            else
            {
                image.source = inActiveImageUrl
            }
        }
    }

    background: Rectangle {
        anchors.fill: parent
        color: "transparent"

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                button.onClicked()
                if(!mouseArea.focus)
                    button.focus = true
            }

            onHoveredChanged: {
                if (!isButtonDisable)
                {
                    if (mouseArea.containsMouse)
                    {
                        image.source = activeImageUrl
                    }
                    else
                    {
                        image.source = inActiveImageUrl
                    }
                }
                else
                {
                    image.source = disableImageUrl
                }
            }
        }

        Image {
            id: image
            anchors.fill: parent
            anchors.leftMargin: parent.width * 8 / 100
            source: isButtonDisable? disableImageUrl : ((button.activeFocus || mouseArea.containsMouse) ? activeImageUrl : inActiveImageUrl)
            fillMode: Image.Stretch
            verticalAlignment: Image.AlignVCenter
        }
    }


    Keys.onReturnPressed:  {
        //console.log("return press")
        button.clicked()
    }
    onClicked: {
        button.focus = true
    }
}
