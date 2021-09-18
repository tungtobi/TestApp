import QtQuick 2.12
import "."

Rectangle {
   id: toastMessage

   property string messageText: ""
   property string imageSrc: ""
   property string borderColor: ""
   property int widthToast: 0
   property int heightToast: 0
   property int durationToast: 0
   width: widthToast
   height: heightToast
   anchors.centerIn: parent
   border.width: 2
   border.color: borderColor
   color: HmiDefines.whiteColor
   radius: 5
   function show(_message, _imageSrc, _borderColor, _width, _height, duration_) {
       durationToast = duration_
       widthToast = _width
       heightToast = _height
       messageText = _message
       imageSrc = _imageSrc
       borderColor = _borderColor
       animations.start()
   }


   Text {
       id: msg
       anchors.left: rectImg.right
       anchors.right: parent.right
       anchors.verticalCenter: rectImg.verticalCenter
       verticalAlignment: Text.AlignVCenter
       horizontalAlignment: Text.AlignHCenter
       text: messageText
       color: "black"
   }

   Rectangle {
        id: rectImg
        height: parent.height - 10
        width: height
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        color: "transparent"
        Image {
            anchors.left: parent.left
            height: parent.height
            width: height
            source: imageSrc
        }
   }

   SequentialAnimation on opacity {
          id: animations
          running: false

          NumberAnimation {
              to: 1
              duration: 555
          }

          PauseAnimation {
              duration: durationToast
          }

          NumberAnimation {
              to: 0
              duration: 555
          }

          onRunningChanged: {
              if(!running){
                  toastMessage.destroy();
              }
          }
      }
}
