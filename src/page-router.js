import React, { lazy, Suspense } from 'react';
import { Route, Routes } from 'react-router-dom';
import LoadingPage from 'pages/_loading';
import MainLayout from 'layouts/main-layout';

const page = (elem) => (
    <Suspense fallback={<LoadingPage />}>
        {elem}
    </Suspense>
);

const IndexPage = lazy(() => import('pages/index'));
const NotFoundPage = lazy(() => import('pages/not-found'));
const HomeworkTaskPage = lazy(() => import('pages/homeworks/task'));
const IntroductionTopicPage = lazy(() => import('pages/topics/introduction'));
const SystemCallsTopicPage = lazy(() => import('pages/topics/system-calls'));


const PageRouter = () => {
    return (
        <Routes>
            <Route element={<MainLayout />}>
                <Route index element={page(<IndexPage />)} />
                <Route path="topics">
                    <Route path="introduction" element={page(<IntroductionTopicPage />)} />
                    <Route path="system-calls" element={page(<SystemCallsTopicPage />)} />
                </Route>
                <Route path="homeworks">
                    <Route path="task/:code" element={page(<HomeworkTaskPage />)} />
                </Route>
            </Route>
            <Route path="/not-found" element={page(<NotFoundPage />)} />
            <Route path="*" element={page(<NotFoundPage />)} />
        </Routes>
    )
}

export default PageRouter;
