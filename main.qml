import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Uplimg")

    SwipeView
    {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page
        {
            Item
            {
                anchors.fill: parent;
                anchors
                {
                    margins: 10;
                }

                ColumnLayout
                {

                    GroupBox
                    {
                        title: "General";
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            CheckBox { text: "Launch on startup"; }
                        }
                    }

                    GroupBox
                    {
                        title: "On successful upload";
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            CheckBox { text: "Play a sound"; }
                            CheckBox { text: "Show notification"; }
                            CheckBox { text: "Show upload progress"; }
                            CheckBox { text: "Copy link in clipboard"; }
                            CheckBox { text: "Open in browser"; }
                        }
                    }
                }
            }
        }

        Page
        {
            Item
            {
                anchors.fill: parent;
                anchors
                {
                    margins: 10;
                }

                ColumnLayout
                {

                    GroupBox
                    {
                        title: "Saving";
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            CheckBox { id: localSave; text: "Save pictures on computer"; }
                            RowLayout
                            {
                                Text { text: "Upload destination"; }
                                ComboBox
                                {
                                    id: destinationType;
                                    model: ["Uplimg official server", "Custom server", "Local only"];
                                    onCurrentIndexChanged:
                                    {
                                        if (currentIndex === 2)
                                        {
                                            localSave.enabled = false;
                                            localSave.checked = true;
                                        }
                                        else
                                        {
                                            localSave.enabled = true;
                                        }
                                    }
                                }
                            }
                            GroupBox
                            {
                                title: "Custom server";
                                enabled: destinationType.currentIndex === 1;
                                GridLayout
                                {
                                    anchors.fill: parent;
                                    columns: 2;

                                    Text { text: "Server's address"; }
                                    TextField { placeholderText: "Server's address"; }
                                    Text { text: "Server's port"; }
                                    TextField { placeholderText: "Remember: https is on 443"; }
                                    Text { text: "Username"; }
                                    TextField { placeholderText: "Username"; }
                                    Text { text: "Password"; }
                                    TextField { placeholderText: "Password"; }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    footer: TabBar
    {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton
        {
            text: qsTr("General")
        }
        TabButton
        {
            text: qsTr("Saving")
        }
    }
}
