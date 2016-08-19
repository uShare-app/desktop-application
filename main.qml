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
                        CheckBox { text: "Copy link in clipboard"; }
                        CheckBox { text: "Open in browser"; }
                    }
                }
            }
        }

        Page
        {
            Label
            {
                text: qsTr("Second page")
                anchors.centerIn: parent
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
