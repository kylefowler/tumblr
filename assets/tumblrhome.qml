import bb.cascades 1.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 1280
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Left;
            verticalAlignment: VerticalAlignment.Center
        }
        topMargin: 10
        bottomMargin: 10
        preferredWidth: 1024 - 800
        preferredHeight: 1280
        Label {
            objectName: "loginName"
            topMargin: 10; bottomMargin: 10;
            layoutProperties: StackLayoutProperties {verticalAlignment: VerticalAlignment.Top; horizontalAlignment: HorizontalAlignment.Center;}
        }
        Label {
            objectName: "url"
            topMargin: 10; bottomMargin: 10;
            layoutProperties: StackLayoutProperties { verticalAlignment: VerticalAlignment.Top; horizontalAlignment: HorizontalAlignment.Center;}
        }
        Button {
		    objectName: "logoutButton"
		    text: "Logout"
        }
        Button {
		    objectName: "refreshButton"
		    text: "Refresh"
        }
        Button {
		    objectName: "postButton"
		    text: "New Post"
        }
        Button {
		    objectName: "reblogButton"
		    text: "Reblog selected"
        }
        Button {
            objectName: "likeButton"
            text: "Like selected"
        }
        Label {
            objectName: "actionStatus"
            text: "Reblogged!"
            topMargin: 10; bottomMargin: 10;
            opacity: 0
        }
        ListView {
            objectName: "blogList"
            preferredWidth: 800
            preferredHeight: 600
            layoutProperties: DockLayoutProperties {
                                  horizontalAlignment: HorizontalAlignment.Right;
                              }
        }
    }
}