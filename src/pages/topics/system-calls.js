import { Divider, Typography } from "antd";
import Container from "components/container";
import Helmet from "react-helmet";

const { Title, Paragraph, Text } = Typography;

const SystemCallsTopicPage = () => {

    return <>
        <Helmet>
            <title>System Calls</title>
        </Helmet>
        <Container>
            <Typography>
                <Title>System Calls</Title>
                <Paragraph>
                    The topic discusses main aspects of hardware and software communication. 
                    Gives brief understanding of functionality exposed by Operating Systems, introduces the concept of <Text strong>System Calls</Text>.
                    Topic includes introduction to <Text strong>POSIX</Text> standard.
                </Paragraph>

                <Title level={4}>
                    Topic Outline
                </Title>
                <ul>
                    <li>How CPU and Memory work together?</li>
                    <li>How does Kernel talk to CPU, RAM and other devices.</li>
                    <li>OS functionality for application development: system calls .</li>
                    <li>POSIX Standard, hardware and software compatibility.</li>
                </ul>
                <Title level={4}>
                    Practice
                </Title>
                <ul>
                    <li>To be defined.</li>
                </ul>
                <Divider />
            </Typography>
            
        </Container>
    </>
}

export default SystemCallsTopicPage;