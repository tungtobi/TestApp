import QtQuick 2.12


ListView {

    function show(text, duration, isGood) {
        model.insert(0, {text: text, duration: duration, isGood: isGood});
    }
    id: root

    z: Infinity
    spacing: 5
    anchors.fill: parent
    anchors.bottomMargin: 10
    verticalLayoutDirection: ListView.BottomToTop

    interactive: false

    displaced: Transition {
        NumberAnimation {
            properties: "y"
            easing.type: Easing.InOutQuad
        }
    }

    delegate: Toast {
        Component.onCompleted: {
            show(text, duration, isGood);
        }
    }

    model: ListModel {id: model}
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
