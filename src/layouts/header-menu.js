import React from "react"
import { Button, Col, Row, Space } from "antd"
import { GithubOutlined } from "@ant-design/icons"
import { Link } from "react-router-dom"

const HeaderMenu = () => {

    return (
            <Row style={{ height: 64}}>
                <Col style={{ width: 250, display: 'flex' }}>
                    <Link
                        to="/"
                        style={{
                            margin: 'auto'
                        }}>
                        <img src={`${process.env.PUBLIC_URL}/favicon.png`} height={50} alt="Linux 101" />
                    </Link>
                </Col>
                <Col flex='auto'>
                        <Space direction="horizontal" style={{float: 'right', padding: '0 8px'}}>
                            <Button shape="circle" type="default" size="large" href="https://github.com/davitp/linux101" target="_blank"><GithubOutlined /></Button>
                        </Space>
                </Col>
            </Row>
    )
}

export default HeaderMenu


