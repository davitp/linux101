import { Col, Row } from 'antd';

export default function Container({ children }) {

    return <Row>
        <Col span={18} offset={3}>
            {children}
        </Col>
    </Row>

}