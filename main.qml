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
                            CheckBox
                            {
                                id: launchOnStartup;
                                text: "Launch on startup";
                                onCheckedChanged: Settings.setValue("LaunchOnStartup", checked);
                            }
                        }
                    }

                    GroupBox
                    {
                        title: "On successful upload";
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            CheckBox
                            {
                                id: playASound;
                                text: "Play a sound";
                                onCheckedChanged: Settings.setValue("PlayASound", checked);
                            }

                            CheckBox
                            {
                                id: showNotification;
                                text: "Show notification";
                                onCheckedChanged: Settings.setValue("ShowNotification", checked);
                            }

                            CheckBox
                            {
                                id: showUploadProgress;
                                text: "Show upload progress";
                                onCheckedChanged: Settings.setValue("ShowUploadProgress", checked);
                            }

                            CheckBox
                            {
                                id: copyLinkInClipboard;
                                text: "Copy link in clipboard";
                                onCheckedChanged: Settings.setValue("CopyLinkInClipboard", checked);
                            }

                            CheckBox
                            {
                                id: openInBrowser;
                                text: "Open in browser";
                                onCheckedChanged: Settings.setValue("OpenInBrowser", checked);
                            }
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
                            CheckBox
                            {
                                id: localSave;
                                text: "Save pictures on computer";
                                onCheckedChanged: Settings.setValue("LocalSave", checked);
                            }

                            RowLayout
                            {
                                Text { text: "Upload destination"; }
                                ComboBox
                                {
                                    id: destinationType;
                                    model: ["Uplimg official server", "Custom server", "Local only"];
                                    currentIndex: Settings.value("UploadDestination");
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
                                        Settings.setValue("UploadDestination", currentIndex);
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

    Component.onCompleted:
    {
        Settings.setValueIfNotSet("LaunchOnStartup", false);
        Settings.setValueIfNotSet("PlayASound", true);
        Settings.setValueIfNotSet("ShowNotification", true);
        Settings.setValueIfNotSet("ShowUploadProgress", false);
        Settings.setValueIfNotSet("CopyLinkInClipboard", false);
        Settings.setValueIfNotSet("OpenInBrowser", true);
        Settings.setValueIfNotSet("LocalSave", false);
        Settings.setValueIfNotSet("UploadDestination", 0);

        launchOnStartup.checked = Settings.boolValue("LaunchOnStartup");
        playASound.checked = Settings.boolValue("PlayASound");
        showNotification.checked = Settings.boolValue("ShowNotification");
        showUploadProgress.checked = Settings.boolValue("ShowUploadProgress");
        copyLinkInClipboard.checked = Settings.boolValue("CopyLinkInClipboard");
        openInBrowser.checked = Settings.boolValue("OpenInBrowser");
        localSave.checked = Settings.boolValue("LocalSave");
    }
}
