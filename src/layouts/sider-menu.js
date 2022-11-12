import { FolderOutlined, HomeOutlined } from "@ant-design/icons"
import { Menu } from "antd"
import { useNavigate } from "react-router-dom"

const menuItems = [
   {
      key: '/home',
      icon: <HomeOutlined />,
      label: 'Home'
   },
   {
      key: '/topics',
      icon: <FolderOutlined />,
      label: 'Topics',
      children: [
         {
            key: '/topics/introduction',
            label: 'Introduction'
         },
         {
            key: '/topics/system-calls',
            label: 'System Calls'
         }
      ]
   }
]



export default function SiderMenu({ collapsed }) {

   const navigate = useNavigate();

   const onKeyChange = key => {

      switch (key) {
         case 'home':
            navigate('/');
            break;
         case 'topic-introduction':
            navigate('/topics/introduction');
            break;
         case 'topic-system-calls':
            navigate('/topics/system-calls');
            break;
         default:
         // do nothing
      }

   }
   return <Menu
      mode="inline"
      defaultSelectedKeys={collapsed ? undefined : ['home']}
      defaultOpenKeys={collapsed ? undefined : ['home']}
      onClick={({ key }) => onKeyChange(key)}
      style={{
         height: '100%',
         borderRight: 0,
      }}
      items={menuItems}
   />

}