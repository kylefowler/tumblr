import Cascades 4.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 600
    }
    ListView {
        objectName: "blogList"
        preferredWidth: 300
        preferredHeight: 600
        layoutProperties: DockLayoutProperties {
                              horizontalAlignment: HorizontalAlignment.Left;
                          }
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Right;
            verticalAlignment: VerticalAlignment.Center
        }
        topMargin: 10
        bottomMargin: 10
        preferredWidth: 1024 - 300
        preferredHeight: 600
        Label {
            objectName: "loginName"
            topMargin: 10; bottomMargin: 10;
            font: SystemFont.H2
            textColor: Color.create("#ffffffff")
            layoutProperties: StackLayoutProperties {verticalAlignment: VerticalAlignment.Top; horizontalAlignment: HorizontalAlignment.Center;}
        }
        Label {
            objectName: "url"
            topMargin: 10; bottomMargin: 10;
            font: SystemFont.H3
            textColor: Color.create("#ffffffff")
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
    }
}