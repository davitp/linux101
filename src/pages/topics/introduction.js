import { Divider, Typography } from "antd";
import Container from "components/container";
import Helmet from "react-helmet";
import { buildTask, taskCodes } from "tasks";

const { Title, Paragraph, Text } = Typography;

const IntroductionTopicPage = () => {

    return <>
        <Helmet>
            <title>Introduction to hardware and software</title>
        </Helmet>
        <Container>
            <Typography>
                <Title>Introduction to hardware and software</Title>
                <Paragraph>
                    The topic covers a brief introduction to concepts such as <Text strong>hardware</Text> and <Text strong>software</Text>.
                    The topic discusses the role of different hardware components such as CPU, Random Access Memory, etc.
                    Next, the topic explains the role of <Text strong>Operating Systems</Text> and<Text strong> Kernel</Text> in the above context.
                </Paragraph>

                <Title level={4}>
                    Topic Outline
                </Title>
                <ul>
                    <li>What is a computer, main components, the role of the Operating System.</li>
                    <li>Brief definition of Operating System.</li>
                    <li>What is UNIX, GNU and Free Software.</li>
                    <li>Kernels: Overview, Minix, Linux, BSD.</li>
                    <li>Overview of existing GNU/Linux distributions.</li>
                </ul>
                <Title level={4}>
                    Practice
                </Title>
                <ul>
                    <li>Setting up a virtual machine with GNU/Linux distribution.</li>
                    <li>Using command line for basic operations: working with files, installing software, etc.</li>
                    <li>Setting up development environment: Git, compiler (gcc/g++), make, etc.</li>
                    <li>Setting up a repository for homeworks in Github: main concepts.</li>
                    <li>Overview of existing GNU/Linux distributions.</li>
                </ul>
                <Divider />
                <Title level={4}>
                    Tasks
                </Title>
                { buildTask(taskCodes.ENV_0, { embed: true }) }
            </Typography>
            
        </Container>
    </>
}

export default IntroductionTopicPage;