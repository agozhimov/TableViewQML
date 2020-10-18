import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

Window {
    id: mainWin
    visible: true

    TableView {
        id: table

        TableViewColumn {
            role: "id_role"
            title: "ID"
        }

        TableViewColumn {
            role: "name_role"
            title: "Name"
        }

        TableViewColumn {
            role: "phone_role"
            title: "Phone"
        }

        anchors.fill: parent

        model: tmodel
    }
}

