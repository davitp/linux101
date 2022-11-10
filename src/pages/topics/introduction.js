import { Typography } from "antd";
import Container from "components/container";
import Helmet from "react-helmet";

const { Title, Paragraph, Text } = Typography;

const IntroductionTopicPage = () => {

    return <>
        <Helmet>
            <title>Topic: Introduction to hardware and software</title>
        </Helmet>
        <Container>
            <Typography>
                <Title>Topic: Introduction to hardware and software</Title>
                <Paragraph>
                    The topic covers brief introduction of concepts such as <Text strong>hardware</Text> and <Text strong>software</Text>. 
                    Topic discusses the role of different hardware components such as CPU, Random Access Memory, etc. 
                    Next, topic explains the role of <Text strong>Operating Systems</Text> and<Text strong> Kernel</Text> in the above context.
                </Paragraph>
            </Typography>
        </Container>
    </>
}

export default IntroductionTopicPage;