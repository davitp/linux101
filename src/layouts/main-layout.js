import React, { useState } from "react"
import { Layout, Menu } from "antd"
import { Outlet, useNavigate } from "react-router-dom"
import { FolderOutlined, HomeOutlined } from "@ant-design/icons"
import HeaderMenu from "./header-menu"

const menuItems = [
   {
      key: 'home',
      icon: <HomeOutlined />,
      label: 'Home'
   },
   {
      key: 'topics',
      icon: <FolderOutlined />,
      label: 'Topics',
      children: [
         {
            key: 'topic-introduction',
            label: 'Introduction'
         }
      ]
   }
]

export default function MainLayout() {

   const [collapsed, setCollapsed] = useState(false)
   const navigate = useNavigate();

   const onKeyChange = key => {

      switch(key){
         case 'home':
            navigate('/');
            break;
         case 'topic-introduction':
            navigate('/topics/introduction');
            break;
         default:
            // do nothing
      }
   
   }

   return (
      <>
         <Layout style={{ minHeight: "100vh" }}>
            <Layout.Header style={{ width: '100%', padding: 0, backgroundColor: 'white', borderBottom: '1px solid #e4e9f0' }}>
               <HeaderMenu />
            </Layout.Header>

            <Layout style={{ backgroundColor: 'white', paddingTop: 18 }}>
               <Layout.Sider width="250px" theme="light"
                  style={{
                     overflow: 'auto',
                     minHeight: '100vh',
                     position: 'relative',
                     borderRight: '1px solid #e4e9f0'
                  }}
                  breakpoint="md"
                  collapsible
                  onCollapse={setCollapsed}>

                  <Menu
                     mode="inline"
                     defaultSelectedKeys={collapsed ? undefined : ['home']}
                     defaultOpenKeys={collapsed ? undefined : ['home']}
                     onClick={({key}) => onKeyChange(key)}
                     style={{
                        height: '100%',
                        borderRight: 0,
                     }}
                     items={menuItems}
                  />
               </Layout.Sider>
               <Layout.Content style={{
                  margin: '18px 18px',
                  padding: '8px 8x',
                  backgroundColor: 'white'
               }}>
                  <Outlet />
               </Layout.Content>
            </Layout>

         </Layout>

      </>
   )
}

